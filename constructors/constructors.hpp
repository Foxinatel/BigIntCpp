#pragma once

#include "../bigint.hpp"
#include "../operators/binary_arithmetic.hpp"

//default constructor
inline BigInt::BigInt () {}

//constructor for integer values
inline BigInt::BigInt (std::integral auto n) {
    if (n < 0) {
        sign = -1;
        n = -n;
    }
    while (n > 0) {
        value.push_back(n % (1l << 32));
        n /= (1l << 32);
    }
}

//constructor for char pointers
inline BigInt::BigInt(const char *chars) : BigInt(std::string(chars)) {}

//constructor for strings
inline BigInt::BigInt (const std::string &str) {
    std::string numstr;
    if (str[0] == '-') {
        sign = -1;
        numstr = str.substr(1);
    } else {
        numstr = str;
    }
    BigInt acc;
    for (size_t i = 0; i < numstr.length(); ++i) {
        acc *= 10;
        acc += (numstr[i] - '0');
    }
    value = acc.value;
}