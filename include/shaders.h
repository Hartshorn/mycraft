#pragma once

#include <GL/glew.h>

#include "../deps/tinycthread/tinycthread.h"

#include "error.h"
#include "structs.h"
#include "util.h"

typedef enum {
	S_BLOCK,
	S_LINE,
	S_TEXT,
	S_SKY
} Shader;

void load_shaders();
static void s_load(Shader);
static void load_block(GLuint program, const char *shader, const char *fragment);
static void load_line(GLuint program, const char *shader, const char *fragment);
static void load_text(GLuint program, const char *shader, const char *fragment);
static void load_sky(GLuint program, const char *shader, const char *fragment);


