#pragma once

#include "../bigint.hpp"

inline BigInt abs(BigInt a) {
    a.sign = 1;
    return a;
}