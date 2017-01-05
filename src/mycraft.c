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

Result set_db_path()
{
	game->mode = MODE_OFFLINE;
	snprintf(game->db_path, MAX_PATH_LENGTH, "%s", DB_PATH);
	
	return OK;
}


int main(int argc, char **argv) 
{

  srand(time(NULL));
  rand();

  if (!glfwInit()) 
    return handle_error(100, "glfwInit()");

  create_window();
  if (!game->window) {
    glfwTerminate();
    return handle_error(200, "create_window()");
  }

  if (glew_init() != GLEW_OK)
    return handle_error(300, "glew_init()");

  gl_init();

  load_textures();
  load_shaders();

  if (set_db_path() != OK)
	  return handle_error(600, "set_db_path()");
	
  free(game);
  glfwTerminate();
}

  



