#pragma once

#include "../utilities.hpp"
#include "../bigint.hpp"
#include "assignment.hpp"
#include "binary_arithmetic.hpp"

BigInt& BigInt::operator+=(BigIntConstructible auto a) {
    *this = *this + BigInt(a);
    return *this;
}

BigInt& BigInt::operator-=(BigIntConstructible auto a) {
    //*this = *this - BigInt(a);
    return *this;
}

BigInt& BigInt::operator*=(BigIntConstructible auto a) {
    *this = *this * BigInt(a);
    return *this;
}

BigInt& BigInt::operator/=(BigIntConstructible auto a) {
    //*this = *this / BigInt(a);
    return *this;
}

BigInt& BigInt::operator%=(BigIntConstructible auto a) {
    //*this = *this % BigInt(a);
    return *this;
}