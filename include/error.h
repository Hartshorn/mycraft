#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int errorno;
	const char *message;
} Error;

int handle_error(int, const char *);

static Error* init_error(int, const char *);

static void print_error(Error *);

static void cleanup_error(Error *);
