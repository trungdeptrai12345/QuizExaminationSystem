#pragma once
#include <string>

namespace Utils {
    std::string readString(const std::string& msg);
    int readInt(const std::string& msg, int min, int max);
    std::string hashPassword(const std::string& plain);
}