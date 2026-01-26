#include "Utils.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <functional>

std::string Utils::hashPassword(const std::string& input) {
    // Demo hash (KHÔNG phải crypto real), nhưng đủ để minh hoạ NFR security trong SRS
    // Nếu GV yêu cầu mạnh hơn, có thể thay bằng SHA256 (thư viện ngoài) -> thường không cần.
    std::hash<std::string> h;
    size_t val = h(input);
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

int Utils::readInt(const std::string& prompt, int minVal, int maxVal) {
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x && x >= minVal && x <= maxVal) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return x;
        }
        std::cout << "Nhap khong hop le. Vui long thu lai!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string Utils::readNonEmpty(const std::string& prompt) {
    while (true) {
        std::cout << prompt;
        std::string s;
        std::getline(std::cin, s);
        if (!s.empty()) return s;
        std::cout << "Khong duoc de trong. Vui long nhap lai!\n";
    }
}
