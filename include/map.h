#pragma once

/*  two macros defined here - one a boolean check for a value inside of
/   an entry, the other a map function. If the entry->value is 0, we skip it.
/   memory written in a union is written in the same location, so writing it
/   to value after "e" would overwrite what is there already.
/   This is used in map.c (map_grow(Map *map)) with an added function call
/   at the end, which is why you need the final end bracket defined - it will
/   need to be added during macro expansion.
*/
#define EMPTY_ENTRY(entry) ((entry)->value == 0)

#define MAP_FOR_EACH(map, ex, ey, ez, ew)                     \
            for (unsigned int i = 0; i <= map->mask; i++) {   \
              MapEntry *entry = map->data + i;                \
              if (EMPTY_ENTRY(entry))                         \
                continue;                                     \
              int ex = entry->e.x + map->dx;                  \
              int ey = entry->e.y + map->dy;                  \
              int ez = entry->e.z + map->dz;                  \
              int ew = entry->e.w;
#define END_MAP_FOR_EACH  }

/* a union means that this structure can be of either of these descriptions:
/  either "value" or "e"
*/
typedef union {
  unsigned int value;
  struct {
    unsigned char x;
    unsigned char y;
    unsigned char z;
    char w;
  } e;
} MapEntry;

typedef struct {
  int dx;
  int dy;
  int dz;
  unsigned int mask;
  unsigned int size;
  MapEntry *data;
} Map;

void map_set_func(int x, int y, int z, int w, void *arg);
int map_set(Map *map, int x, int y, int z, int w);