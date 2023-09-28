#include <app.hpp>

namespace {

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

}

namespace Graphic_core {

std::shared_ptr<App> App::getApp() {
    if (!obj_) {
        obj_ = std::make_shared<App> ();
    }

    return obj_;
}

void App::initWindow(const char *windowName, const int windowWidth, const int windowHeigth, 
                    const int GLFWCtxVerMin, const int GLFWCtxVerMaj) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLFWCtxVerMaj);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLFWCtxVerMin);
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    w_ = glfwCreateWindow(windowWidth, windowHeigth, windowName, NULL, NULL);
    if (!w_) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    sz_ = {windowWidth, windowHeigth};

    glfwMakeContextCurrent(w_);
    glfwSwapInterval(0); // for disable vsync
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glfwSetFramebufferSizeCallback(w_, framebuffer_size_callback);
    pixel_buffer_.resize(sz_.first * sz_.second * 3);
    pixel_update_buffer_.resize(sz_.first * sz_.second);
}

void App::createProgram(const char *vertName, const char *fragName) {
    s_ = Shader(vertName, fragName);
}

void App::createBuffers() {
    float vertices[] = {
        -1.0f, -1.0f,
        3.0f, -1.0f,
        -1.0f,  3.0f
    };
    glGenVertexArrays(1, &VAO_);
    glGenBuffers(1, &VBO_);

    glBindVertexArray(VAO_);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glGenTextures(1, &texture_);
    glBindTexture(GL_TEXTURE_2D, texture_); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glGenBuffers(1, &PBO_);
}

void App::updateGPUBuffer() {
    glBindTexture(GL_TEXTURE_2D, texture_);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, PBO_);
    glBufferData(GL_PIXEL_UNPACK_BUFFER, sz_.first * sz_.second * 3, NULL, GL_STREAM_DRAW);
    void* mappedBuffer = glMapBuffer(GL_PIXEL_UNPACK_BUFFER, GL_WRITE_ONLY);

    memcpy(mappedBuffer, pixel_buffer_.data(), sz_.first * sz_.second * 3);
    glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sz_.first, sz_.second, 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

char App::setPixel(const int x, const int y, const int abgr) {
    if ((x >= sz_.first) || (y >= sz_.second) || (y < 0) || (x < 0))
        return false;

    int index = x + y * sz_.first;
    if(pixel_update_buffer_[index] == check_value)
        return false;

    int place = 3 * index;
    pixel_update_buffer_[index] = check_value;
    pixel_buffer_[place]   = 0xFF & (abgr);
    pixel_buffer_[place+1] = 0xFF & (abgr >> 8);
    pixel_buffer_[place+2] = 0xFF & (abgr >> 16);
    return true;
}

void App::useProgram() {
    check_value = !check_value;
    s_.use();

    glBindVertexArray(VAO_);
    glActiveTexture(GL_TEXTURE0);
    s_.setUniform("tex", 0);
    glBindTexture(GL_TEXTURE_2D, texture_);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void App::destroy() {
    glfwTerminate();
}

}