#include <app.hpp>

namespace {

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

float vertices[] = {
    -1., -1.,
    3., -1.,
    -1., 3.
};
}

namespace Graphic_core {

std::shared_ptr<App> App::getApp() {
    if (!obj_) {
        obj_ = std::make_shared<App> ();
    }

    return obj_;
}

void App::initWindow(const char *windowName, const int windowWidth, const int windowHeigth, const int GLFWCtxVerMin, const int GLFWCtxVerMaj) {
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
    glfwMakeContextCurrent(w_);
    glfwSwapInterval(0); // for disable vsync
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glfwSetFramebufferSizeCallback(w_, framebuffer_size_callback);
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
}

void App::useProgram() {
    s_.use();
    glBindVertexArray(VAO_);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void App::destroy() {
    glfwTerminate();
}

}