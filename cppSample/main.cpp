#include <graphic.hpp>
#include "calculate.hpp"

int main() {
    init("lol kek cheburek", 800, 600);

    int b = 0;
    while (!shouldClose())
    {
        ++b;
        updateGPUBuffer();
        for (int i = 0; i < 800; ++i) {
            for (int j = 0; j < 600; ++j) {
                setPixel(i, j, b%255, b%255, b%255);
            }
        }
        draw();
    }

    destroy();
    return 0;
}