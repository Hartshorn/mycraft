#pragma once

#include "config.h"
#include "db.h"
// #include "noise.h" this is a deps file ...

typedef void (*world_func)(int, int, int, int, void *);

void create_world(int p, int q, world_func func, void *arg);