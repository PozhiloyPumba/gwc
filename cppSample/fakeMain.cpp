#include "graphic.hpp"
#include "src.h"

char fillCircle(int xc, int yc, int r, int color, int *next) {
    char flag = 0;
    for (int y = -r; y <= r; y++)
        for (int x = -r; x <= r; x++)
            if (x * x + y * y <= r * r) {
                int locflag = setPixel(xc + x, yc + y, color);
                flag |= locflag;
                if (locflag) {
                    next[0] += xc + x;
                    next[1] += yc + y;
                    ++next[2];
                }
            }
    return flag;
}

void fakeMain() {
    for (int j = 0; j < 100; ++j) {
        const int sz = int(sizeof(arr) / sizeof(*arr));
        char flags[sz] = {};
        int coords[sz][3] = {};
        int radius = 2;
        char flag = 1;
        for (int i = 0; i < sz; ++i)
            fillCircle(arr[i][0], arr[i][1], radius, 0, coords[i]);

        while (flag) {
            flag = 0;
            ++radius;
            for (int i = 0; i < sz; ++i) {
                if (flags[i])
                    continue;
                flags[i] = !fillCircle(arr[i][0], arr[i][1], radius, arr[i][2],
                                       coords[i]);
                flag |= !flags[i];
            }
        }
        updateGPUBuffer();
        for (int i = 0; i < sz; ++i) {
            arr[i][0] = coords[i][0] / coords[i][2];
            arr[i][1] = coords[i][1] / coords[i][2];
        }
        flush();
    }
}