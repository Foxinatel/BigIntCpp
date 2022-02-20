#pragma once

#include "../bigint.hpp"

inline BigInt BIabs(BigInt a) {
    a.negative = 0;
    return a;
}