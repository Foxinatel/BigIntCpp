#pragma once

#include "../bigint.hpp"

const BigInt& BigInt::operator=(BigIntConstructible auto a) {
    value = a.value;
    negative = a.negative;
    return *this;
}