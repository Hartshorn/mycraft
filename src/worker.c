#include "../include/worker.h"


#include <stdio.h> // just for testing


Result init_worker_threads(Model *game)
{
  for (int i = 0; i < WORKERS_COUNT; i++)
  {
    Worker *worker = game->workers + i;
    worker->index = i;
    worker->state = WORKER_IDLE;
    mtx_init(&worker->mtx, mtx_plain);
    cnd_init(&worker->cnd);
    thrd_create(&worker->thrd, worker_run, worker);
  }
  return OK;
}


int worker_run(void *arg)
{
    Worker *worker = (Worker *)arg;
    int running = 1;
    while (running) {
        mtx_lock(&worker->mtx);
        while(worker->state != WORKER_BUSY) {
            cnd_wait(&worker->cnd, &worker->mtx);
        }
        mtx_unlock(&worker->mtx);
        WorkerItem *item = &worker->item;
        if (item->load) {
            load_chunk(item);
        }
        compute_chunk(item);
        mtx_lock(&worker->mtx);
        worker->state = WORKER_DONE;
        mtx_unlock(&worker->mtx);
    }
    return 0;
}

void load_chunk(WorkerItem *item)
{
    int p = item->p;
    int q = item->q;
    Map *block_map = item->block_maps[1][1];
    Map *light_map = item->light_maps[1][1];
    create_world(p, q, map_set_func, block_map);
    db_load_blocks(block_map, p, q);
    db_load_lights(light_map, p, q);
}

void compute_chunk(WorkerItem *item)
{
    fprintf(stdout, "compute_chunk(WorkerItem *item)");
}