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

extern "C" void flush() {
    auto app = Graphic_core::App::getApp();
    if (glfwWindowShouldClose(app->getWindow())) {
        throw std::runtime_error("user want to close window!!!");
    }

    glClear(GL_COLOR_BUFFER_BIT);
    app->useProgram();
    glfwSwapBuffers(app->getWindow());
    glfwPollEvents();
}
