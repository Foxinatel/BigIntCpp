#pragma once

#include "../bigint.hpp"
#include "assignment.hpp"
#include "binary_arithmetic.hpp"

inline BigInt& BigInt::operator+=(const BigInt &a) {
    *this = *this + a;
    return *this;
}

inline BigInt& BigInt::operator-=(const BigInt &a) {
    *this = *this - a;
    return *this;
}

inline BigInt& BigInt::operator*=(const BigInt &a) {
    *this = *this * a;
    return *this;
}

inline BigInt& BigInt::operator/=(const BigInt &a) {
    *this = *this / a;
    return *this;
}

inline BigInt& BigInt::operator%=(const BigInt &a) {
    *this = *this % a;
    return *this;
}