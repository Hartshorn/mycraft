#pragma once

#include <GL/glew.h>
#include <stdlib.h>
#include <string.h>

#include "../deps/lodepng/lodepng.h"

#include "error.h"

void load_png_texture(const char *);
void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height);
GLuint load_program(const char *path1, const char *path2);
