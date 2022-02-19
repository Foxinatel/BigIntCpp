#pragma once

#include "../bigint.hpp"
#include "./relational.hpp"
#include "./binary_arithmetic.hpp"

inline std::ostream& operator<<(std::ostream &out, BigInt num) {
    //if (num.value.size() == 0) num.value = {0};
    std::string str = (num.negative?"-":"");
    while (num.value.size()) {
        str.insert(0, 1, char(num % 10 + '0'));
        num /= 10;
    }
    return out << str;
}