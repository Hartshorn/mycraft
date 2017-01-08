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

void s_load(GLuint, Shader, Attrib);
static void load_block(Attrib, GLuint, const char *, const char *);
static void load_line(Attrib, GLuint, const char *, const char *);
static void load_text(Attrib, GLuint, const char *, const char *);
static void load_sky(Attrib, GLuint, const char *, const char *);


