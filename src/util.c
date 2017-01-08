#include "../include/util.h"

#include <stdio.h> // just to check test is working!

void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height)
{
	unsigned int size = width * height * 4;
	unsigned int stride = sizeof(char) * width * 4;
	unsigned char *new_data = malloc(sizeof(unsigned char) * size);

	if (!new_data)
		handle_error(FLIP_IMAGE_VERTICAL_ERROR, "flip_image_vertical() error");

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
		handle_error(LODEPNG_DECODE32_FILE_ERROR, "lodepng_decode32_file()");

	flip_image_vertical(data, width, height);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	free(data);
}

char* load_file(const char *path)
{
	FILE *file = fopen(path, "rb");
	fseek(file, 0, SEEK_END);
	int length = ftell(file);
	rewind(file);
	char *data = calloc(length + 1, sizeof(char));
	fread(data, 1, length, file);
	fclose(file);
	return data;
}

GLuint make_shader(GLenum type, const char* source)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		GLchar *info = calloc(length, sizeof(GLchar));
		glGetShaderInfoLog(shader, length, NULL, info);
		fprintf(stderr, "glCompileShaderFailed: \n%s\n", info);
		free(info);
	}
	return shader;
}

GLuint load_shader(GLenum type, const char *path)
{
	char *data = load_file(path);
	GLuint result = make_shader(type, data);
	free(data);
	return result;
}

GLuint make_program(const char *shader1, const char *shader2)
{
	GLuint program = glCreateProgram();
	glAttachShader(program, shader1);
	glAttachShader(program, shader2);
	glLinkProgram(program);
	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE) {
		GLint length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		GLchar *info = calloc(length, sizeof(GLchar));
		glGetProgramInfoLog(program, length, NULL, info);
		fprintf(stderr, "glLinkProgram failed: %s\n", info);
		free(info);
	}
	glDetachShader(program, shader1);
	glDetachShader(program, shader2);
	glDeleteShader(shader1);
	glDeleteShader(shader2);
	return program;
}

GLuint load_program(const char *path1, const char *path2)
{
	GLuint shader1 = load_shader(GL_VERTEX_SHADER, path1);
	GLuint shader2 = load_shader(GL_FRAGMENT_SHADER, path2);
	GLuint program = make_program(shader1, shader2);
	return program;
}

Result set_db_path(Model *game)
{
	game->mode = MODE_OFFLINE;
	snprintf(game->db_path, MAX_PATH_LENGTH, "%s", DB_PATH);
	
	return OK;
}
