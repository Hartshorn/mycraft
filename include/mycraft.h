#pragma once


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "../deps/tinycthread/tinycthread.h"

#include "../include/error.h"
#include "../include/config.h"
#include "../include/structs.h"
#include "../include/callbacks.h"
#include "../include/textures.h"
#include "../include/shaders.h"
#include "../include/worker.h"

void create_window(); 
int glew_init(); 
void gl_init();
Result set_db_path();
