#ifndef __GRAPHIC_API__
#define __GRAPHIC_API__

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

extern "C" GLFWwindow *init(const char *windowName, const int windowWidth, const int windowHeigth);

extern "C" void destroy();

#endif
