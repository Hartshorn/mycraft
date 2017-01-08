#include "../include/shaders.h"



void shader_load(GLuint program, Shader shader, Attrib attrib)
{
	switch (shader) {
		case S_BLOCK:
			load_block(attrib, program, "shaders/block_vertex.glsl", "shaders/block_fragment.glsl");
			break;
		case S_LINE:
			load_line(attrib, program, "shaders/line_vertex.glsl", "shaders/line_fragment.glsl");
			break;
		case S_TEXT:
			load_text(attrib, program, "shaders/text_vertex.glsl", "shaders/text_fragment.glsl");
			break;
		case S_SKY:
			load_sky(attrib, program, "shaders/sky_vertex.glsl", "shaders/sky_fragment.glsl");
			break;
		default:
			handle_error(500, "unknown shader");
			break;
	}
}


static void load_block(Attrib block_attrib, GLuint program, const char *shader, const char *fragment) 
{
	program = load_program(shader, fragment);
	block_attrib.program 	= program;
	block_attrib.position 	= glGetAttribLocation(program,  "position");
	block_attrib.normal 	= glGetAttribLocation(program,  "normal");
	block_attrib.uv 		= glGetUniformLocation(program, "uv");
	block_attrib.matrix 	= glGetUniformLocation(program, "matrix");
	block_attrib.sampler 	= glGetUniformLocation(program, "sampler");
	block_attrib.extra1 	= glGetUniformLocation(program, "sky_sampler");
	block_attrib.extra2  	= glGetUniformLocation(program, "daylight");
	block_attrib.extra3 	= glGetUniformLocation(program, "fog_distance");
	block_attrib.extra4 	= glGetUniformLocation(program, "ortho");
	block_attrib.camera 	= glGetUniformLocation(program, "camera");
	block_attrib.timer 		= glGetUniformLocation(program, "timer");
}


static void load_line(Attrib line_attrib, GLuint program, const char *shader, const char *fragment) 
{
	program = load_program(shader, fragment);
	line_attrib.program 	= program;
	line_attrib.position 	= glGetAttribLocation(program, "position");
	line_attrib.matrix 		= glGetUniformLocation(program, "matrix");
}


static void load_text(Attrib text_attrib, GLuint program, const char *shader, const char *fragment) 
{
	program = load_program(shader, fragment);
	text_attrib.program 	= program;
	text_attrib.position 	= glGetAttribLocation(program, "position");
	text_attrib.uv 			= glGetAttribLocation(program, "uv");
	text_attrib.matrix 		= glGetUniformLocation(program, "matrix");
	text_attrib.sampler 	= glGetUniformLocation(program, "sampler");
	text_attrib.extra1 		= glGetUniformLocation(program, "is_sign");
}


static void load_sky(Attrib sky_attrib, GLuint program, const char *shader, const char *fragment) 
{
	program = load_program(shader, fragment);
	sky_attrib.program 		= program;
	sky_attrib.position 	= glGetAttribLocation(program, "position");
	sky_attrib.normal 		= glGetAttribLocation(program, "normal");
	sky_attrib.uv 			= glGetAttribLocation(program, "uv");
	sky_attrib.matrix 		= glGetUniformLocation(program, "matrix");
	sky_attrib.sampler 		= glGetUniformLocation(program, "sampler");
	sky_attrib.timer 		= glGetUniformLocation(program, "timer");
}


