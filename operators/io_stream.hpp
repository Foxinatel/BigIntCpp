#pragma once

#include "../bigint.hpp"
#include "./relational.hpp"
#include "./binary_arithmetic.hpp"

#include <iostream>

inline std::ostream& operator<<(std::ostream &out, BigInt num) {
    if (num.value.size() == 0) num.value = {0};
    std::string str = "";
    bool negflag = num.sign < 0;
    while (num.value.size()) {
        str.insert(0, 1, uint32_t(num%10)+'0');
        num /= 10;
    }
    str.insert(0,negflag?"-":"");
    return out << str;
}