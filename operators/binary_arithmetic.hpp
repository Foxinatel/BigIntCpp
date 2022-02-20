#pragma once

#include "../bigint.hpp"
#include "./relational.hpp"
#include "../functions/functions.hpp"

BigInt operator+(const BigInt &, const BigInt &);
BigInt operator-(const BigInt &, const BigInt &);
BigInt operator*(const BigInt &, const BigInt &);
BigInt operator/(const BigInt &, const BigInt &);
BigInt operator%(const BigInt &, const BigInt &);

//ripple addition
inline BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt newval; 
    if (a.sign * b.sign < 0) {
        newval = a - b;
        newval.sign = a.sign;
    } else {
        const size_t size1 = a.value.size();
        const size_t size2 = b.value.size();
        const size_t s = std::max(size1, size2);
        bool overflow = false;
        for (size_t i = 0; i < s || overflow; ++i) {
            const uint64_t newdig = uint64_t(i < size1 ? a.value[i] : 0) +
                                    uint64_t(i < size2 ? b.value[i] : 0) +
                                    overflow;
            newval.value.push_back(newdig);
            overflow = newdig >> 32;
        }
        newval.sign = a.sign;
    }
    return newval;
}

inline BigInt operator-(const BigInt &a, const BigInt &b) {
    BigInt newval;
    newval.sign = a.sign;
    if (a.sign * b.sign < 0) {
        newval = a + b;
    } else {
        const BigInt absa = abs(a);
        const BigInt absb = abs(b);
        if (absb > absa) newval.sign *= -1;
        const BigInt max = std::max(absa, absb);
        const BigInt min = std::min(absa, absb);
        bool underflow = false;
        for (size_t i = 0; i < max.value.size(); ++i) {
            const uint32_t newdig = max.value[i] -
                                    (i < min.value.size() ? min.value[i] : 0) -
                                    underflow;
            newval.value.push_back(newdig);
            underflow = newdig > max.value[i];
        }
        while (newval.value.size() > 0 && newval.value.back() == 0) {newval.value.pop_back();}
    }
    return newval;
}

inline BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt accumulator;
    accumulator.sign = a.sign * b.sign;
    for (size_t i = 0; i < a.value.size(); ++i) {
        for (size_t j = 0; j < b.value.size(); ++j) {
            BigInt temp;
            temp.value.resize(i+j);
            uint64_t val = uint64_t(a.value[i])*b.value[j];
            if (val == 0) continue;
            temp.value.push_back(val % (1l<<32));
            if (val >> 32) temp.value.push_back(val >> 32);
            accumulator += temp;
        }
    }
    return accumulator;
}

inline BigInt operator/(const BigInt &N, const BigInt &D) {
    BigInt Q, R;
    for (size_t i = 0; i < N.value.size()*32; ++i) {
        const size_t index = N.value.size()*32 - i - 1;
        R *= 2;
        if (R == 0) R.value = {0};
        R.value[0] |= ((N.value[index/32] >> (index%32)) & 1);
        if (R >= D) {
            R -= D;
            while (Q.value.size() <= (index/32)) Q.value.push_back(0);
            Q.value[index/32] |= (1u << (index%32));
        }
    }
    return Q;
}

inline BigInt operator%(const BigInt &N, const BigInt &D) {
    BigInt Q, R;
    for (size_t i = 0; i < N.value.size()*32; ++i) {
        const size_t index = N.value.size()*32 - i - 1;
        R *= 2;
        if (R == 0) R.value = {0};
        R.value[0] |= ((N.value[index/32] >> (index%32)) & 1);
        if (R >= D) {
            R -= D;
            while (Q.value.size() <= (index/32)) Q.value.push_back(0);
            Q.value[index/32] |= (1u << (index%32));
        }
    }
    return R;
}