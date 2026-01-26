#pragma once
#include <string>

namespace Utils {
    std::string hashPassword(const std::string& input);
    int readInt(const std::string& msg, int min, int max);
    std::string readString(const std::string& msg);
}