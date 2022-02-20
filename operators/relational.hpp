#pragma once

#include "../bigint.hpp"

inline bool operator<(const BigInt& a, const BigInt& b) {
    if (a.negative && !b.negative) return true;
    if (!a.negative && b.negative) return false;
    const bool negative = (a.negative && b.negative);
    if (a.value.size() < b.value.size()) return !negative;
    if (a.value.size() > b.value.size()) return negative;
    for (ssize_t i = a.value.size()-1; i>=0; --i) {
        if (a.value[i] < b.value[i]) return !negative;
        if (a.value[i] > b.value[i]) return negative;
    }
    return false;
}

inline bool operator>(const BigInt& a, const BigInt& b) {
    if (!a.negative && b.negative) return true;
    if (a.negative && !b.negative) return false;
    const bool negative = (a.negative && b.negative);
    if (a.value.size() > b.value.size()) return !negative;
    if (a.value.size() < b.value.size()) return negative;
    for (ssize_t i = a.value.size()-1; i>=0; --i) {
        if (a.value[i] > b.value[i]) return !negative;
        if (a.value[i] < b.value[i]) return negative;
    }
    return false;
}

inline bool operator<=(const BigInt& a, const BigInt& b) {return !(a>b);}
inline bool operator>=(const BigInt& a, const BigInt& b) {return !(a<b);}

inline bool operator==(const BigInt& a, const BigInt& b) {
    if (a.negative != b.negative) return false;
    if (a.value.size() != b.value.size()) return false;
    for (size_t i = 0; i < a.value.size(); ++i) {
        if (a.value[i] != b.value[i]) return false;
    }
    return true;
}

inline bool operator!=(const BigInt& a, const BigInt& b) {return !(a==b);}