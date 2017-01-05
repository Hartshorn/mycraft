#pragma once

#include "map.h"
#include "sign.h"


typedef enum {
	OK,
	FAIL
} Result;

typedef struct {
  int p;
  int q;
  int load;
  Map *block_maps[3][3];
  Map *light_maps[3][3];
  int miny;
  int minx;
  int faces;
  GLfloat *data;
} WorkerItem;

typedef struct {
  int index;
  int state;
  thrd_t thrd;
  mtx_t mtx;
  cnd_t cnd;
  WorkerItem item;
} Worker;


typedef struct {
  Map map;
  Map lights;
  SignList signs;
  int p;
  int q;
  int faces;
  int sign_faces;
  int dirty;
  int miny;
  int maxy;
  GLuint buffer;
  GLuint sign_buffer;
} Chunk;

typedef struct {
  float x;
  float y;
  float z;
  float rx;
  float ry;
  float t;
} State;

typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
  State state;
  State state1;
  State state2;
  GLuint buffer;
} Player;

typedef struct {
  int x;
  int y;
  int z;
  int w;
} Block;

typedef struct {
  GLFWwindow *window;
  Worker workers[WORKERS_COUNT];
  Chunk chunks[MAX_CHUNKS];
  int chunk_count;
  int create_radius;
  int render_radius;
  int delete_radius;
  int sign_radius;
  Player players[MAX_PLAYERS];
  int player_count;
  int typing;
  char typing_buffer[MAX_TEXT_LENGTH];
  int message_index;
  char messages[MAX_MESSAGES][MAX_TEXT_LENGTH];
  int width;
  int height;
  int observe1;
  int observe2;
  int flying;
  int item_index;
  int scale;
  int ortho;
  float fov;
  int supress_char;
  int mode;
  int mode_changed;
  char db_path[MAX_PATH_LENGTH];
  int server_port;
  int day_length;
  int time_changed;
  Block block0;
  Block block1;
  Block copy0;
  Block copy1;
} Model;


