#ifndef __GRAPHIC_API__
#define __GRAPHIC_API__

extern "C" void init(const char *windowName, const int windowWidth, const int windowHeigth);
extern "C" int shouldClose();
extern "C" void draw();
extern "C" void destroy();

#endif
