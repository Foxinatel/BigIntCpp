#pragma once

#include "../utilities.hpp"
#include "../bigint.hpp"
#include "./relational.hpp"
#include "../functions/functions.hpp"
#include <cstddef>

#include "./io_stream.hpp"
#include <iostream>

BigInt operator+(BigInt, BigInt);
BigInt operator-(BigInt, BigInt);
BigInt operator*(BigInt, BigInt);
BigInt operator/(BigInt, BigInt);
BigInt operator%(BigInt, BigInt);

//ripple addition
inline BigInt operator+(BigInt a, BigInt b) {
    BigInt newval; 
    if (a.negative ^ b.negative) {
        newval = a-b;
        newval.negative = a.negative;
    } else {
        const size_t size1 = a.value.size();
        const size_t size2 = b.value.size();
        const size_t s = M_max(size1, size2);
        bool overflow = false;
        for (size_t i = 0; i < s || overflow; ++i) {
            const uint64_t newdig = uint64_t(i < size1 ? a.value[i] : 0) +
                                    uint64_t(i < size2 ? b.value[i] : 0) +
                                    overflow;
            newval.value.push_back(newdig);
            overflow = newdig >> 32;
        }
        newval.negative = a.negative;
    }
    return newval;
}

//Definitely not optimal, will revisit later
//I wonder if there's something like Wallace trees for this
inline BigInt operator*(BigInt a, BigInt b) {
    std::vector<BigInt> vecpool;
    const size_t size1 = a.value.size();
    const size_t size2 = b.value.size();
    for (size_t i = 0; i < size1; ++i) {
        for (size_t j = 0; j < size2; ++j) {
            BigInt tempvec;
            tempvec.value.resize(i+j);
            uint64_t val = a.value[i]*b.value[j];
            if (val == 0) continue;
            tempvec.value.push_back(val & 0xFFFFFFFF);
            if (val >> 32) tempvec.value.push_back(val >> 32);
            vecpool.push_back(tempvec);
        }
    }
    BigInt newval;
    newval.negative = a.negative ^ b.negative;
    for (auto elem : vecpool) newval = newval + elem;
    return newval;
}

inline BigInt operator-(BigInt a, BigInt b) {
    BigInt newval;
    newval.negative = a.negative;
    if (a.negative ^ b.negative) {
        newval = a+b;
    } else {
        const BigInt absa = abs(a);
        const BigInt absb = abs(b);
        if (absb > absa) newval.negative = !newval.negative;
        const BigInt max = M_max(absa, absb);
        const BigInt min = M_min(absa, absb);
        std::cout << '\n' << max << '\n' << min << '\n';
        bool underflow = false;
        for (size_t i = 0; i < max.value.size(); ++i) {
            const uint32_t newdig = max.value[i] -
                                    (i < min.value.size() ? min.value[i] : 0) -
                                    underflow;
            newval.value.push_back(newdig);
            underflow = newdig > max.value[i];
        }
    }
    return newval;
}

inline BigInt operator+(BigInt a, BigIntConstructible auto n) {return a + BigInt(n);}
inline BigInt operator+(BigIntConstructible auto n, BigInt a) {return a + BigInt(n);}

inline BigInt operator*(BigInt a, BigIntConstructible auto n) {return a * BigInt(n);}
inline BigInt operator*(BigIntConstructible auto n, BigInt a) {return a * BigInt(n);}

//inline BigInt operator-(BigInt a, BigIntConstructible auto n) {return a - BigInt(n);}
//inline BigInt operator-(BigIntConstructible auto n, BigInt a) {return a - BigInt(n);}

//inline BigInt operator/(BigInt a, BigIntConstructible auto n) {return a / BigInt(n);}
//inline BigInt operator/(BigIntConstructible auto n, BigInt a) {return a / BigInt(n);}

//inline BigInt operator%(BigInt a, BigIntConstructible auto n) {return a % BigInt(n);}
//inline BigInt operator%(BigIntConstructible auto n, BigInt a) {return a % BigInt(n);}