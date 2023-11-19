#include <stdio.h>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, unsigned long long> instrs;

#define TRIPLET
// #define PAIR

extern "C" void instrLogger(char *opName) {
#if 0

    printf("%s\n", opName);

#endif
#if defined(TRIPLET)

    static std::string prev;
    static std::string prevprev;
    std::string cur = prevprev + std::string("+") + prev +
                      std::string("+") + std::string(opName);
    prevprev = prev;
    prev = opName;

    ++instrs[cur];

#elif defined(PAIR)

    static std::string prev;
    std::string cur = prev + std::string("+") + std::string(opName);
    prev = opName;
    ++instrs[cur];

#else

    ++instrs[opName];

#endif
}