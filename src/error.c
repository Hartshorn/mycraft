#include "../include/error.h"



static Error* init_error(int n, const char *s)
{
	Error *e = malloc(sizeof(Error));
	e->errorno = n;
	e->message = s;
	return e;
}

static void print_error(Error *e)
{
	fprintf(stderr, "Error %d: %s\n", e->errorno, e->message);
}

static void cleanup_error(Error *e)
{
	free(e);
}

int handle_error(int n, const char *s)
{
	Error *e = init_error(n, s);
	print_error(e);
	cleanup_error(e);
	
	return -1;
}
