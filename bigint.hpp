#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <concepts>

#include "utilities.hpp"

//store in reverse order
struct BigInt {

    bool negative = 0;
    std::vector<uint32_t> value;

    BigInt ();
    BigInt(BigInt const&) = default;
    BigInt (const std::integral auto);
    BigInt (const char*);
    BigInt (const std::string);

    //Assignment
    BigInt& operator=(const BigInt&);

    // Unary arithmetic operators:
    BigInt operator+() const;   // unary +
    BigInt operator-() const;   // unary -

    // Arithmetic-assignment operators:
    BigInt& operator+=(const BigInt&);
    BigInt& operator-=(const BigInt&);
    BigInt& operator*=(const BigInt&);
    BigInt& operator/=(const BigInt&);
    BigInt& operator%=(const BigInt&);

    // Increment and decrement operators:
    BigInt& operator++();       // pre-increment
    BigInt& operator--();       // pre-decrement
    BigInt operator++(int);     // post-increment
    BigInt operator--(int);     // post-decrement

    operator uint32_t();
};

template<class T>
concept BigIntConstructible = requires (T a) {BigInt(a);};