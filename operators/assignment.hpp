#pragma once

#include "../bigint.hpp"

inline BigInt &BigInt::operator=(const BigInt &other) {
    value = other.value;
    negative = other.negative;
    return *this;
}