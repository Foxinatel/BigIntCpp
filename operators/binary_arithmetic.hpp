#pragma once

#include "../utilities.hpp"
#include "../bigint.hpp"

//ripple addition
inline auto operator+(BigInt a, BigInt b) {
    BigInt newvec{}; 
    const size_t size1 = a.value.size();
    const size_t size2 = b.value.size();
    const size_t s = M_max(size1, size2);
    bool overflow = false;
    for (size_t i = 0; i < s || overflow; ++i) {
        const uint64_t newval = uint64_t(i < size1 ? a.value[i] : 0) +
                                uint64_t(i < size2 ? b.value[i] : 0) +
                                overflow;
        newvec.value.push_back(newval);
        overflow = newval >> 32;
    }
    return newvec;
}

//Definitely not optimal, will revisit later
//I wonder if there's something like Wallace trees for this
inline auto operator*(BigInt a, BigInt b) {
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
    BigInt newvec;
    newvec.negative = a.negative ^ b.negative;
    for (auto elem : vecpool) newvec = newvec + elem;
    return newvec;
}

inline auto operator+(BigInt a, BigIntConstructible auto n) {return a + BigInt(n);}
inline auto operator+(BigIntConstructible auto n, BigInt a) {return a + BigInt(n);}

inline auto operator*(BigInt a, BigIntConstructible auto n) {return a * BigInt(n);}
inline auto operator*(BigIntConstructible auto n, BigInt a) {return a * BigInt(n);}

inline auto operator-(BigInt a, BigIntConstructible auto n) {return a - BigInt(n);}
inline auto operator-(BigIntConstructible auto n, BigInt a) {return a - BigInt(n);}

inline auto operator/(BigInt a, BigIntConstructible auto n) {return a / BigInt(n);}
inline auto operator/(BigIntConstructible auto n, BigInt a) {return a / BigInt(n);}

inline auto operator%(BigInt a, BigIntConstructible auto n) {return a % BigInt(n);}
inline auto operator%(BigIntConstructible auto n, BigInt a) {return a % BigInt(n);}