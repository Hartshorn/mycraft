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
	GLuint program = 0;

	switch (s) {
		case S_BLOCK:
			load_block(program, "shaders/block_vertex.glsl", "shaders/block_fragment.glsl");
			break;
		case S_LINE:
			load_line(program, "shaders/line_vertex.glsl", "shaders/line_fragment.glsl");
			break;
		case S_TEXT:
			load_text(program, "shaders/text_vertex.glsl", "shaders/text_fragment.glsl");
			break;
		case S_SKY:
			load_sky(program, "shaders/sky_vertex.glsl", "shaders/sky_fragment.glsl");
			break;
		default:
			handle_error(500, "unknown shader");
			break;
	}
}

static void load_block(GLuint program, const char *shader, const char *fragment) 
{
	Attrib block_attrib = {0};
	program = load_program(shader, fragment);
	block_attrib.program = program;
	block_attrib.position = glGetAttribLocation(program, "position");
	block_attrib.normal = glGetAttribLocation(program, "normal");
	block_attrib.uv = glGetUniformLocation(program, "uv");
	block_attrib.matrix = glGetUniformLocation(program, "matrix");
	block_attrib.sampler = glGetUniformLocation(program, "sampler");
	block_attrib.extra1 = glGetUniformLocation(program, "sky_sampler");
	block_attrib.extra2  = glGetUniformLocation(program, "daylight");
	block_attrib.extra3 = glGetUniformLocation(program, "fog_distance");
	block_attrib.extra4 = glGetUniformLocation(program, "ortho");
	block_attrib.camera = glGetUniformLocation(program, "camera");
	block_attrib.timer = glGetUniformLocation(program, "timer");

}
static void load_line(GLuint program, const char *shader, const char *fragment) {}
static void load_text(GLuint program, const char *shader, const char *fragment) {}
static void load_sky(GLuint program, const char *shader, const char *fragment) {}


