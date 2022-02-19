#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <concepts>

#include "utilities.hpp"

struct BigInt;
template<class T>
concept BigIntConstructible = requires (T a) {BigInt(a);};

inline BigInt operator*(BigInt a, BigIntConstructible auto n);
inline BigInt operator*(BigIntConstructible auto n, BigInt a);

//store in reverse order
struct BigInt {

    bool negative = 0;
    std::vector<uint32_t> value;

    BigInt ();
    BigInt (const std::integral auto);
    BigInt (const std::string);

    //Assignment
    const BigInt& operator=(BigIntConstructible auto);

    // Unary arithmetic operators:
    BigInt operator+() const;   // unary +
    BigInt operator-() const;   // unary -

    // Arithmetic-assignment operators:
    BigInt& operator+=(BigIntConstructible auto);
    BigInt& operator-=(BigIntConstructible auto);
    BigInt& operator*=(BigIntConstructible auto);
    BigInt& operator/=(BigIntConstructible auto);
    BigInt& operator%=(BigIntConstructible auto);

    // Increment and decrement operators:
    BigInt& operator++();       // pre-increment
    BigInt& operator--();       // pre-decrement
    BigInt operator++(int);     // post-increment
    BigInt operator--(int);     // post-decrement

    operator uint();
};