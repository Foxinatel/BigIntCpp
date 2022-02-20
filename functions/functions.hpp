#pragma once

#include "../bigint.hpp"

inline BigInt abs(BigInt a) {
    a.negative = 0;
    return a;
}