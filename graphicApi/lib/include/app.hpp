#ifndef __APP_HPP__
#define __APP_HPP__

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
// clang-format on

#include "shader.hpp"
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

namespace Graphic_core {

class App final {
private:
    GLFWwindow *w_;
    Shader s_;
    unsigned VAO_, VBO_, PBO_, texture_;
    std::pair<int, int> sz_;
    std::vector<unsigned char> pixel_buffer_;
    std::vector<bool> pixel_update_buffer_;
    bool check_value = true;

    static inline std::shared_ptr<App> obj_ = nullptr;

public:
    static std::shared_ptr<App> getApp();
    void initWindow(const char *windowName, const int windowWidth = 800,
                    const int windowHeigth = 600, const int GLFWCtxVerMin = 3,
                    const int GLFWCtxVerMaj = 3);
    GLFWwindow *getWindow() { return w_; }
    void createProgram(const char *, const char *);
    void createBuffers();
    void updateGPUBuffer();
    char setPixel(const int x, const int y, const int abgr);
    void useProgram();
    void destroy();
};

} // namespace Graphic_core

#endif