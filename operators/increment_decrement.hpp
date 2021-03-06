#pragma once

#include "../bigint.hpp"
#include "assignment.hpp"
#include "binary_arithmetic.hpp"


inline BigInt& BigInt::operator++() {
    return *this += 1;
}

inline BigInt& BigInt::operator--() {
    return *this -= 1;
}

inline BigInt BigInt::operator++(int) {
    BigInt temp = *this;
    ++*this;
    return temp;
}

inline BigInt BigInt::operator--(int) {
    BigInt temp = *this;
    --*this;
    return temp;
}