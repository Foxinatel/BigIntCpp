#pragma once

#include "../bigint.hpp"

inline BigInt &BigInt::operator=(const BigInt &other) {
    value = other.value;
    sign = other.sign;
    return *this;
}