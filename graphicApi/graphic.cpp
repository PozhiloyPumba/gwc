#include "graphic.hpp"
#include <app.hpp>
#include <iostream>

extern "C" void updateGPUBuffer() {
    auto app = Graphic_core::App::getApp();
    app->updateGPUBuffer();
}

extern "C" char setPixel(const int x, const int y, const int abgr) {
    auto app = Graphic_core::App::getApp();
    return app->setPixel(x, y, abgr);
}

extern "C" void draw() {
    auto app = Graphic_core::App::getApp();
    glClear(GL_COLOR_BUFFER_BIT);
    app->useProgram();
    glfwSwapBuffers(app->getWindow());
    glfwPollEvents();
}
