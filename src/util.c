#include "../include/util.h"

#include <stdio.h> // just to check test is working!

void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height)
{
	unsigned int size = width * height * 4;
	unsigned int stride = sizeof(char) * width * 4;
	unsigned char *new_data = malloc(sizeof(unsigned char) * size);

	for (unsigned int i = 0; i < height; i++) {
		unsigned int j = height - i - 1;
		memcpy(new_data + j * stride, data + i * stride, stride);
	}

	memcpy(data, new_data, size);
	free(new_data);
}

void load_png_texture(const char *file) 
{
	fprintf(stdout, "load_png_texture() called with %s\n\n", file);

	unsigned int error;
	unsigned char *data;
	unsigned int width, height;

	error = lodepng_decode32_file(&data, &width, &height, file);

	if (error)
		handle_error(900, "lodepng_decode32_file()");

	flip_image_vertical(data, width, height);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	free(data);
}

GLuint load_program(const char *path1, const char *path2)
{
	fprintf(stdout, "load_program(%s, %s)\n", path1, path2);
	
	GLuint success = 0;

	return success;
}
