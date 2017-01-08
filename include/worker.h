#pragma once


#include "../deps/tinycthread/tinycthread.h"

#include "structs.h"
#include "world.h"

Result init_worker_threads(Model *game);
int worker_run(void *arg);
void load_chunk(WorkerItem *item);
void compute_chunk(WorkerItem *item);