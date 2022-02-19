#pragma once

#include "../bigint.hpp"

const BigInt& BigInt::operator=(BigIntConstructible auto a) {
    BigInt temp{a};
    this->value = temp.value;
    this->negative = temp.negative;
    return *this;
}