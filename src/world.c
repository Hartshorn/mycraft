#include "../include/world.h"

#include <stdio.h> // just for testing

void create_world(int p, int q, world_func func, void *arg)
{
    fprintf(stdout, "create_world(%d, %d, somefunc, somearg)", p, q);
}