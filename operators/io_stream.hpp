#pragma once

#include "../bigint.hpp"

#include <iomanip>

inline std::ostream& operator<<(std::ostream &out, BigInt num) {
    out << std::hex << (num.negative?"-":"") << num.value[num.value.size()-1];
    for (ssize_t i = num.value.size()-2; i >= 0; --i) {
        out << std::setw(8) << std::setfill('0') << num.value[i]; 
    }
    return out;
}