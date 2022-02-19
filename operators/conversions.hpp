#pragma once

#include "../bigint.hpp"

inline BigInt::operator uint() {
    return value[0];
}