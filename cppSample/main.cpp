#include <graphic.hpp>

int main() {
    GLFWwindow *w = init("lol kek cheburek", 800, 600);
    
    while (!glfwWindowShouldClose(w))
    {
        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    destroy();
    return 0;
}