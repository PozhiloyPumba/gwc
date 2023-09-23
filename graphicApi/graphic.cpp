#include "graphic.hpp"
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

extern "C" GLFWwindow *init(const char *windowName, const int windowWidth, const int windowHeigth) {
    const int GLFWCtxVerMin = 3, GLFWCtxVerMaj = 3;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFWCtxVerMaj);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFWCtxVerMin);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeigth, windowName, NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0); // for disable vsync
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}

extern "C" void destroy() {
    glfwTerminate();
}