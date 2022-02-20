#pragma once

#include "../bigint.hpp"

inline BigInt BigInt::operator+() const {return *this;}

inline BigInt BigInt::operator-() const {
    BigInt temp{*this};
    temp.sign = -temp.sign;
    return temp;
}