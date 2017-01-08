#pragma once

#include <GL/glew.h>
#include <stdlib.h>
#include <string.h>

#include "../deps/lodepng/lodepng.h"
#include "../deps/tinycthread/tinycthread.h"

#include "error.h"
#include "config.h"
#include "structs.h"


char* load_file(const char *path);
GLuint make_shader(GLenum type, const char* source);
GLuint load_shader(GLenum type, const char *path);
GLuint make_program(const char *shader1, const char *shader2);
void load_png_texture(const char *);
void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height);
GLuint load_program(const char *path1, const char *path2);
Result set_db_path(Model *game);
