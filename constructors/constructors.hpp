#include "../bigint.hpp"
#include "../operators/binary_arithmetic.hpp"

#include <concepts>

//default constructor
inline BigInt::BigInt () {}

//copy constuctor
inline BigInt::BigInt (const BigInt &n) {
    negative = n.negative;
    value = n.value;
}

//constructor for integer values
inline BigInt::BigInt (const std::integral auto n) {
    if (n < 0) negative = true;
    auto absn = M_abs(n);
    while (absn > 0) {
        value.push_back(absn % (1l << 32));
        absn /= (1l << 32); //after my time in Haskell, I can never look at >>= the same way again
    }
}

//For the sake of my sanity, strings are currently handled as hex
inline BigInt::BigInt (const std::string str) {
    if (str[0] == '-') negative = true;
    const std::string numstr = negative ? str.substr(1) : str;
    BigInt acc;
    for (ssize_t i = str.length()-1; i>=0; --i) {
        acc *= 10;
        acc += (str[i] - '0');
    }
    value = acc.value;
}