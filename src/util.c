#include "../include/util.h"

#include <stdio.h> // just to check test is working!


void load_png_texture(const char *file) 
{
	fprintf(stdout, "load_png_texture() called with %s\n\n", file);
}

GLuint load_program(const char *path1, const char *path2)
{
	fprintf(stdout, "load_program(%s, %s)\n", path1, path2);
	
	GLuint success = 0;

	return success;
}
