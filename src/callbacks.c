#include "../include/callbacks.h"

#include <stdio.h>  // here for testing

void key_callback(GLFWwindow *window, int x, int y, int z, int w) 
{
	fprintf(stdout, "key_callback() called with x: %d, y: %d, z: %d, w: %d\n", x, y, z, w);
}
void char_callback(GLFWwindow *window, unsigned int x) 
{
	fprintf(stdout, "char_callback() called with x: %d\n", x);
}

void scroll_callback(GLFWwindow *window, double x, double y) 
{
	fprintf(stdout, "scroll_callback() called with x: %f, y: %f\n", x, y);
}

void mouse_callback(GLFWwindow *window, int x, int y, int z) 
{
	fprintf(stdout, "mouse_callback() called with x: %d, y: %d, z: %d\n", x, y, z);
}
