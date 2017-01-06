#include "../include/map.h"

#include <stdio.h> // just for testing

void map_set_func(int x, int y, int z, int w, void *arg)
{
    fprintf(stdout, "map_set_func(%d, %d, %d, %d, void *arg)", x, y, z, w);
}


int map_set(Map *map, int x, int y, int z, int w)
{
    return 0;
}