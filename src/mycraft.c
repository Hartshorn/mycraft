#include "../include/mycraft.h"

static Model model;
static Model *game = &model;



void create_window() 
{
  int window_width = WINDOW_WIDTH;
  int window_height = WINDOW_HEIGHT;

  GLFWmonitor *monitor = NULL;

  if (FULLSCREEN) {
    int mode_count;
    monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *modes = glfwGetVideoModes(monitor, &mode_count);
    window_width = modes[mode_count - 1].width;
    window_height = modes[mode_count - 1].height;
  
  }
  game->window = glfwCreateWindow(window_width, window_height, "myCraft", monitor, NULL);
}

int glew_init() 
{
	glfwMakeContextCurrent(game->window);
	glfwSwapInterval(VSYNC);
	glfwSetInputMode(game->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetKeyCallback(game->window, key_callback);
	glfwSetCharCallback(game->window, char_callback);
	glfwSetMouseButtonCallback(game->window, mouse_callback);
	glfwSetScrollCallback(game->window, scroll_callback);
	
	return glewInit();
}

void gl_init()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glLogicOp(GL_INVERT);
	glClearColor(0, 0, 0, 1);
}

int main(int argc, char **argv) 
{

  srand(time(NULL));
  rand();

  if (!glfwInit()) 
    return handle_error(GLFW_INIT_ERROR, "glfwInit()");

  create_window();
  if (!game->window) {
    glfwTerminate();
    return handle_error(CREATE_WINDOW_ERROR, "create_window()");
  }

  if (glew_init() != GLEW_OK)
    return handle_error(GLEW_INIT_ERROR, "glew_init()");

  gl_init();

  load_textures();

  GLint program         = 0;
  Attrib block_attrib   = {0};
  Attrib line_attrib    = {0};
  Attrib text_attrib    = {0};
  Attrib sky_attrib     = {0};
  shader_load(program, S_BLOCK, block_attrib);
  shader_load(program, S_LINE, line_attrib);
  shader_load(program, S_TEXT, text_attrib);
  shader_load(program, S_SKY, sky_attrib);

  if (set_db_path(game) != OK)
	  return handle_error(SET_DB_PATH_ERROR, "set_db_path()");

  game->create_radius = CREATE_CHUNK_RADIUS;
  game->render_radius = RENDER_SIGN_RADIUS;
  game->delete_radius = DELETE_CHUNK_RADIUS;
  game->sign_radius   = RENDER_SIGN_RADIUS;

  if (init_worker_threads(game) != OK)
    return handle_error(INIT_WORKER_THREADS_ERROR, "init_worker_threads()");

  

  // free(game);
  glfwTerminate();
}

  



