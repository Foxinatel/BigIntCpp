#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <concepts>

#include "utilities.hpp"

struct BigInt;
template<class T>
concept BigIntConstructible = requires (T a) {BigInt(a);};

//store in reverse order
struct BigInt {

    bool negative = 0;
    std::vector<uint32_t> value;

    //default constructor
    BigInt () {}

    //copy constuctor
    BigInt (const BigInt &n) {
        negative = n.negative;
        value = n.value;
    }

    //constructor for integer values
    BigInt (std::integral auto n) {
        if (n < 0) negative = true;
        auto absn = M_abs(n);
        while (absn > 0) {
            value.push_back(absn % (1l << 32));
            absn /= (1l << 32); //after my time in Haskell, I can never look at >>= the same way again
        }
    }

    //For the sake of my sanity, strings are currently handled as hex
    BigInt (std::string str) {
        for (ssize_t i = str.length()-8; i > 0; i-=8) {
            value.push_back(std::stol(str.substr(i,8),nullptr,16));
        }
        value.push_back(std::stol(str.substr(0,str.length()%8),nullptr,16));
    }

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

    // Conversion functions:
    std::string to_string() const;
    int to_int() const;
    long to_long() const;
    std::integral auto to_long_long() const;

    // Random number generating functions:
    friend BigInt big_random(size_t);
};