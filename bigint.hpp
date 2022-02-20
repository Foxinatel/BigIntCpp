#pragma once

#include <compare>
#include <cstdint>
#include <vector>
#include <string>
#include <concepts>

//store in reverse order
struct BigInt {

    int sign = 1;
    std::vector<uint32_t> value;

    BigInt ();
    BigInt(BigInt const&) = default;
    BigInt (std::integral auto);
    BigInt (const char*);
    BigInt (const std::string&);

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

    std::strong_ordering operator<=>(const BigInt&) const;
    bool operator>(const BigInt&) const = default;
    bool operator<(const BigInt&) const = default;
    bool operator>=(const BigInt&) const = default;
    bool operator<=(const BigInt&) const = default;
    bool operator==(const BigInt&) const = default;
    bool operator!=(const BigInt&) const = default;

    explicit operator uint32_t();
};