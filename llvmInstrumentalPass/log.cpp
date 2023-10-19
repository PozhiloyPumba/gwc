#include <stdio.h>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, unsigned long long> instrs;

// #define TRIPLET
// #define PAIR

extern "C" void instrLogger(char *opName) {
#if 0

    printf("%s\n", opName);

#endif
#if defined(TRIPLET)

    static std::string prev;
    static std::string prevprev;
    std::string cur = std::string(opName) + std::string("+") + prev +
                      std::string("+") + prevprev;
    prevprev = prev;
    prev = opName;

    ++instrs[cur];

#elif defined(PAIR)

    static std::string prev;
    std::string cur = std::string(opName) + std::string("+") + prev;
    prev = opName;
    ++instrs[cur];

#else

    ++instrs[opName];

#endif
}