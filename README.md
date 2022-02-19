# BigIntCPP
The goal of this project is to create a fast interface for dealing with arbitrarily large integers. There are already libraries for this, most notably https://github.com/faheel/BigInt, however that makes use of strings with a base-10 representation to perform arithmetic.
This new implementation makes use of a dynamic array of uint32_t, essentially allowing us to perform computations (much more efficiently) in base 2^32.

Additionally, operator overloading makes use of C++20 concepts to allow any type that can construct a BigInt to work with no extra configuration

## TODO
* Change string constructor from hex to decimal
* Change IO from hex to decimal
* Bitwise operations ??
* Constexpr ???
* Many more fun things
