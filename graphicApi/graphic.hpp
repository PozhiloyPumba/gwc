#ifndef __GRAPHIC_API__
#define __GRAPHIC_API__

extern "C" void init(const char *windowName, const int windowWidth, const int windowHeigth);
extern "C" int shouldClose();
extern "C" void updateGPUBuffer();
extern "C" void setPixel(const int x, const int y, const unsigned char r, const unsigned char g, const unsigned char b);
extern "C" void draw();
extern "C" void destroy();

#endif
