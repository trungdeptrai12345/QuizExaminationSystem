#include "Utils.h"
#include <iostream>
#include <functional>
#include <limits>

std::string Utils::hashPassword(const std::string& input) {
    std::hash<std::string> h;
    return std::to_string(h(input));
}

int Utils::readInt(const std::string& msg, int min, int max) {
    int x;
    while (true) {
        std::cout << msg;
        if (std::cin >> x && x >= min && x <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Nhap sai, thu lai!\n";
    }
}

std::string Utils::readString(const std::string& msg) {
    std::string s;
    do {
        std::cout << msg;
        std::getline(std::cin, s);
    } while (s.empty());
    return s;
}
