#ifndef __GRAPHIC_API__
#define __GRAPHIC_API__

extern "C" void updateGPUBuffer();
extern "C" char setPixel(const int x, const int y, const int abgr);
extern "C" void flush();

#endif
