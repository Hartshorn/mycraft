#include "../include/mycraft.h"

static Model model;
static Model *game = &model;


int main(int argc, char **argv) 
{
  srand(time(NULL));
  rand();

  if (!glfwInit()) 
    return handle_error(GLFW_INIT_ERROR, "glfwInit()");

  create_window(game);
  if (!game->window) {
    glfwTerminate();
    return handle_error(CREATE_WINDOW_ERROR, "create_window()");
  }

  if (glew_init(game) != GLEW_OK)
    return handle_error(GLEW_INIT_ERROR, "glew_init()");

  gl_init();

  load_textures();

  GLint program         =  0;
  Attrib block_attrib   = {0};
  Attrib line_attrib    = {0};
  Attrib text_attrib    = {0};
  Attrib sky_attrib     = {0};
  shader_load(program, S_BLOCK, block_attrib);
  shader_load(program, S_LINE,  line_attrib);
  shader_load(program, S_TEXT,  text_attrib);
  shader_load(program, S_SKY,   sky_attrib);
  
  if (set_db_path(game) != OK)
	  return handle_error(SET_DB_PATH_ERROR, "set_db_path()");

  game->create_radius = CREATE_CHUNK_RADIUS;
  game->render_radius = RENDER_SIGN_RADIUS;
  game->delete_radius = DELETE_CHUNK_RADIUS;
  game->sign_radius   = RENDER_SIGN_RADIUS;

  if (init_worker_threads(game) != OK)
    return handle_error(INIT_WORKER_THREADS_ERROR, "init_worker_threads()");


  
  // while (1) {

  // }
  // free(game);
  glfwTerminate();
}

  



