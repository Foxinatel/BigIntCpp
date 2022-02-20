#pragma once

#include "../bigint.hpp"

inline BigInt::operator uint32_t() {
    return value[0];
}