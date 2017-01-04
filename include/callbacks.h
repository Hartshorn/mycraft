#pragma once

#include <GLFW/glfw3.h>


void key_callback(GLFWwindow *, int, int, int, int);
void char_callback(GLFWwindow *, unsigned int);
void scroll_callback(GLFWwindow *, double, double);
void mouse_callback(GLFWwindow *, int, int, int);
