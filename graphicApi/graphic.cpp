#include "graphic.hpp"
#include <app.hpp>
#include <iostream>

extern "C" void init(const char *windowName, const int windowWidth, const int windowHeigth) {
    const int GLFWCtxVerMin = 3, GLFWCtxVerMaj = 3;
    auto app = Graphic_core::App::getApp();
    app->initWindow(windowName, windowWidth, windowHeigth, 3, 3);
    app->createProgram("../graphicApi/lib/shaders/common.vert", "../graphicApi/lib/shaders/common.frag");
    app->createBuffers();
}

extern "C" int shouldClose() {
    auto app = Graphic_core::App::getApp();
    return glfwWindowShouldClose(app->getWindow());
}

extern "C" void updateGPUBuffer() {
    auto app = Graphic_core::App::getApp();
    app->updateGPUBuffer();
}

extern "C" void setPixel(const int x, const int y, const unsigned char r, const unsigned char g, const unsigned char b) {
    auto app = Graphic_core::App::getApp();
    app->setPixel(x, y, r, g, b);
}

extern "C" void draw() {
    auto app = Graphic_core::App::getApp();
    glClear(GL_COLOR_BUFFER_BIT);
    app->useProgram();
    glfwSwapBuffers(app->getWindow());
    glfwPollEvents();
}

extern "C" void destroy() {
    auto app = Graphic_core::App::getApp();
    app->destroy();
}