#pragma once

#include <GL/glew.h>

#include "error.h"
#include "util.h"

typedef enum {
	T_TEXTURE,
	T_FONT,
	T_SKY,
	T_SIGN
} Texture;

void load_textures();
static void t_load(Texture);
static void load_tex();
static void load_font();
static void load_sky();
static void load_sign();
