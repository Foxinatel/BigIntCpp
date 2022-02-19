#pragma once

#include "../bigint.hpp"

inline BigInt abs(BigInt a) {
    BigInt temp{a};
    temp.negative = 0;
    return temp;
}