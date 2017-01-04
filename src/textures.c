#include "../include/textures.h"



void load_textures() 
{
	t_load(T_TEXTURE);
	t_load(T_FONT);
	t_load(T_SKY);
	t_load(T_SIGN);
}

static void t_load(Texture t) 
{
	switch (t) {
		case T_TEXTURE:
			load_tex();
			break;
		case T_FONT:
			load_font();
			break;
		case T_SKY:
			load_sky();
			break;
		case T_SIGN:
			load_sign();
			break;
		default:
			handle_error(400, "unknown texture type");
			break;
	}
}

static void load_tex() {}
static void load_font() {}
static void load_sky() {}
static void load_sign() {}
