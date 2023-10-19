#include <app.hpp>

#ifdef INSTRUMENTAL_PASS
#include <iostream>
#include <string>
#include <unordered_map>

extern std::unordered_map<std::string, unsigned long long> instrs;
#endif

extern "C" void fakeMain();

int main() {
    auto app = Graphic_core::App::getApp();
    app->initWindow("fox", 800, 600);
    app->createProgram("../graphicApi/lib/shaders/common.vert",
                       "../graphicApi/lib/shaders/common.frag");
    app->createBuffers();

    try {
        fakeMain();
    } catch (const std::runtime_error &error) {
        if (std::string(error.what()) !=
            std::string("user want to close window!!!"))
            throw error;
    }
#if not defined(INSTRUMENTAL_PASS)
    while (!glfwWindowShouldClose(app->getWindow()))
        glfwPollEvents();
#endif
    app->destroy();

#ifdef INSTRUMENTAL_PASS
    for (auto &el : instrs) {
        std::cout << el.first << " " << el.second << std::endl;
    }
#endif

    return 0;
}