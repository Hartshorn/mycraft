#pragma once


#include "../deps/tinycthread/tinycthread.h"

#include "structs.h"
#include "world.h"


int worker_run(void *arg);
void load_chunk(WorkerItem *item);
void compute_chunk(WorkerItem *item);