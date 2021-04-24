#include "../include/calculator.h"
#include <iostream>
#include <string>

int main() {
    std::string line;

    while (true) {
        getline(std::cin, line);
        const std::string &result = Calculator::Calculate(line);
        std::cout << result;
    }

    return 0;
}