#include <app.hpp>

void fakeMain();

int main() {
    auto app = Graphic_core::App::getApp();
    app->initWindow("fox", 800, 600);
    app->createProgram("../graphicApi/lib/shaders/common.vert", "../graphicApi/lib/shaders/common.frag");
    app->createBuffers();

    fakeMain();

    while (!glfwWindowShouldClose(app->getWindow()));
    app->destroy();

    return 0;
}