#pragma once

#include <GL/glew.h>

#include "error.h"

typedef enum {
	S_BLOCK,
	S_LINE,
	S_TEXT,
	S_SKY
} Shader;

void load_shaders();
static void s_load(Shader);
static void load_block();
static void load_line();
static void load_text();
static void load_sky();


