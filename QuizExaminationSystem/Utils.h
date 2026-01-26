#pragma once
#pragma once
#include <string>

namespace Utils {
    std::string hashPassword(const std::string& input);

    int readInt(const std::string& prompt, int minVal, int maxVal);
    std::string readNonEmpty(const std::string& prompt);
}
