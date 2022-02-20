#pragma once

#include "../bigint.hpp"
#include <compare>

inline std::strong_ordering BigInt::operator<=>(const BigInt &other) const {
    auto cmp = sign <=> other.sign;
    if (cmp != 0) return cmp;
    const auto &a = sign < 0 ? other : *this;
    const auto &b = sign < 0 ? *this : other;
    cmp = size(a.value) <=> size(b.value);
    if (cmp != 0) return cmp;
    for (auto i = size(a.value); i != 0; --i) {
        cmp = a.value[i - 1] <=> b.value[i - 1];
        if (cmp != 0) return cmp;
    }
    return cmp;
}