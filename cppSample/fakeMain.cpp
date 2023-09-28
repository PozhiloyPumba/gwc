#include "graphic.hpp"

void fakeMain() {
    static int b = 0;
    ++b;
    updateGPUBuffer();
    for (int i = 0; i < 800; ++i) {
        for (int j = 0; j < 600; ++j) {
            setPixel(i, j, b%255 + ((b%255) << 8) + ((b%255) << 16));
        }
    }
    draw();
}