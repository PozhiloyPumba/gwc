#include <stdio.h>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, unsigned long long> instrs;

extern "C" void instrLogger(char *opName) {
#if 0
        printf("%s\n", opName);
#endif

    ++instrs[opName];
}