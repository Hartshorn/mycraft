#pragma once

#include <stdio.h>
#include <stdlib.h>

#define GLFW_INIT_ERROR				100
#define CREATE_WINDOW_ERROR 		200
#define GLEW_INIT_ERROR				300
#define FLIP_IMAGE_VERTICAL_ERROR	400
#define SET_DB_PATH_ERROR			500
#define INIT_WORKER_THREADS_ERROR	600
#define LODEPNG_DECODE32_FILE_ERROR 700

typedef struct {
	int errorno;
	const char *message;
} Error;

int handle_error(int, const char *);

static Error* init_error(int, const char *);

static void print_error(Error *);

static void cleanup_error(Error *);
