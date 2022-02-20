#pragma once

#include "../bigint.hpp"
#include "assignment.hpp"
#include "binary_arithmetic.hpp"

inline BigInt& BigInt::operator+=(const BigInt &a) {
    return *this = *this + a;
}

inline BigInt& BigInt::operator-=(const BigInt &a) {
    return *this = *this - a;
}

inline BigInt& BigInt::operator*=(const BigInt &a) {
    return *this = *this * a;
}

inline BigInt& BigInt::operator/=(const BigInt &a) {
    return *this = *this / a;
}

inline BigInt& BigInt::operator%=(const BigInt &a) {
    return *this = *this % a;
}