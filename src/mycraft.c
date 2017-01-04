
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "../deps/tinycthread/tinycthread.h"
#include "../include/map.h"
#include "../include/sign.h"


#define WORKERS_COUNT     4
#define MAX_CHUNKS        8192
#define MAX_TEXT_LENGTH   256
#define MAX_NAME_LENGTH   32
#define MAX_PLAYERS       128
#define MAX_MESSAGES	  4
#define WINDOW_WIDTH	  1024
#define WINDOW_HEIGHT	  768
#define MAX_PATH_LENGTH   256
#define FULLSCREEN	  0





/************************************
/      Structure Definitions
*************************************/

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



static Model model;
static Model *game = &model;




void create_window() {
  // set the default window size if not fullscreen
  int window_width = WINDOW_WIDTH;
  int window_height = WINDOW_HEIGHT;

  // craeate a new monitor
  GLFWmonitor *monitor = NULL;

  // if we are using fullscreen, get the mode count from the primary monitor,
  // then set the width and height from that
  if (FULLSCREEN) {
    int mode_count;
    monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *modes = glfwGetVideoModes(monitor, &mode_count);
    window_width = modes[mode_count - 1].width;
    window_height = modes[mode_count - 1].height;
  }
  // set the global game structure with the newly created window.
  game->window = glfwCreateWindow(window_width, window_height, "myCraft", monitor, NULL);
}

int main(int argc, char **argv) {

/*
1. initialize rand
  Random Number generation. Pretty standard stuff. Seed with time.
*/
  srand(time(NULL));
  rand();
/*
2. GLFW Window Initialization
  openGL Library - used to make windows and control keyboard input.
  Pretty important.  First we need to initialize it.
*/
  if (!glfwInit())
    return -1;
/*
  Then we need to create a new window and set our DataStructure with it, and
  if it doesnt work, terminate.
*/
  create_window();
  if (!game->window) {
    glfwTerminate();
    return -1;
  }


}
