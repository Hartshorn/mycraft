#include "../include/shaders.h"


void load_shaders() 
{
	s_load(S_BLOCK);
	s_load(S_LINE);
	s_load(S_TEXT);
	s_load(S_SKY);
}

static void s_load(Shader s)
{
	switch (s) {
		case S_BLOCK:
			load_block();
			break;
		case S_LINE:
			load_line();
			break;
		case S_TEXT:
			load_text();
			break;
		case S_SKY:
			load_sky();
			break;
		default:
			handle_error(500, "unknown shader");
			break;
	}
}

static void load_block() {}
static void load_line() {}
static void load_text() {}
static void load_sky() {}


