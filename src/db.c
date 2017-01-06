#include "../include/db.h"

#include <stdio.h> // just for testing

void db_load_lights(Map *map, int p, int q)
{
    fprintf(stdout, "db_load_lights(map, %d, %d)", p, q);
}

void db_load_blocks(Map *map, int p, int q)
{
    fprintf(stdout, "db_load_lights(map, %d, %d)", p, q);
}