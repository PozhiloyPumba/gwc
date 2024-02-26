#include <iostream>

#include "driver.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Give filename" << std::endl;
        return 0;
    }

    std::fstream code(argv[1], std::ios::in);
    if (!code.is_open()) {
        throw std::runtime_error("Can't open input file");
    }
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(code.rdbuf());

    yy::FrontendDriver driver(argv[1]);

    driver.parse();
    driver.dump(std::cout);

    std::cin.rdbuf(cinbuf);
    return 0;
}