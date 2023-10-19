#include "graphic.hpp"

extern "C" char fillCircle(int xc, int yc, int r, int color, int *next) {
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

extern "C" void fakeMain() {
    int arr[][3] = {
        {425, 536, 13974511}, {151, 368, 3572079},  {440, 249, 1591737},
        {3, 363, 4020334},    {715, 400, 6731484},  {58, 444, 15049432},
        {512, 555, 13193426}, {311, 331, 2822364},  {37, 103, 2708939},
        {656, 347, 505435},   {133, 358, 7584055},  {470, 494, 2201812},
        {147, 36, 12949952},  {211, 396, 11288287}, {451, 494, 3202092},
        {789, 392, 10526177}, {171, 367, 6475432},  {797, 484, 11629877},
        {186, 228, 5563096},  {167, 351, 13589823}, {505, 250, 3208161},
        {353, 284, 10462034}, {196, 117, 13461283}, {194, 257, 15139700},
        {103, 276, 12291396}, {646, 144, 1097829},  {188, 217, 13558239},
        {673, 10, 11114889},  {660, 520, 1556342},  {624, 169, 2951914},
        {394, 43, 2414789},   {51, 14, 16103385},   {569, 373, 15724377},
        {425, 523, 16143020}, {211, 568, 14574142}, {787, 224, 755813},
        {712, 54, 1316433},   {651, 459, 1672796},  {525, 230, 15763870},
        {129, 527, 10295048}, {631, 220, 9377424},  {4, 416, 12654176},
        {601, 32, 6459850},   {252, 593, 5256075},  {54, 385, 14883775},
        {115, 78, 8514895},   {604, 434, 3404590},  {20, 183, 1018311},
        {7, 326, 12269577},   {73, 18, 6594307},    {0, 456, 10733656},
        {479, 244, 2849870},  {16, 40, 7429552},    {322, 445, 7354436},
        {429, 465, 12181642}, {633, 257, 5046100},  {39, 327, 8084592},
        {256, 530, 16435783}, {367, 29, 9214164},   {245, 552, 1027154},
        {232, 288, 14172151}, {93, 425, 10404819},  {530, 496, 2685554},
        {205, 545, 9891471},  {110, 427, 7628983},  {298, 346, 11452609},
        {633, 359, 3394207},  {609, 407, 3486714},  {398, 49, 15366155},
        {63, 527, 6160162},   {311, 96, 105981},    {727, 201, 9827702},
        {630, 316, 13555200}, {699, 169, 4481560},  {731, 347, 12098681},
        {100, 381, 12245631}, {770, 247, 13267674}, {529, 123, 11677846},
        {411, 211, 13468432}, {459, 342, 14129095}, {433, 181, 10508253},
        {704, 268, 7340572},  {683, 273, 6896895},  {705, 3, 11830786},
        {66, 490, 1521645},   {694, 326, 7597392},  {169, 359, 13177975},
        {135, 265, 4607890},  {92, 451, 5972511},   {720, 29, 5711389},
        {711, 582, 11496075}, {167, 469, 791786},   {44, 583, 2635077},
        {630, 46, 9946804},   {262, 160, 6162150},  {457, 574, 14793056},
        {415, 266, 13430405}, {16, 283, 7321896},   {5, 245, 3194004},
        {331, 137, 3298150}};

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