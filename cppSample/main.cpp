#include <graphic.hpp>
#include "calculate.hpp"

int main() {
    init("lol kek cheburek", 800, 600);

    while (!shouldClose())
    {
        draw();
    }

    destroy();
    return 0;
}