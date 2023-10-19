#include <stdio.h>

extern "C" void instrLogger(char *opName) { printf("%s\n", opName); }