#include <app.hpp>

void fakeMain();

int main() {
    auto app = Graphic_core::App::getApp();
    app->initWindow("fox", 800, 600);
    app->createProgram("../graphicApi/lib/shaders/common.vert", "../graphicApi/lib/shaders/common.frag");
    app->createBuffers();

    while (!glfwWindowShouldClose(app->getWindow()))
    {
        fakeMain();
    }

    app->destroy();
    return 0;
}