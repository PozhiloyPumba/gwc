#ifndef __GRAPHIC_API__
#define __GRAPHIC_API__

extern "C" void updateGPUBuffer();
extern "C" void setPixel(const int x, const int y, const int abgr);
extern "C" void draw();

#endif
