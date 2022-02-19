# BigIntCPP
The goal of this project is to create a fast interface for dealing with arbitrarily large integers. There are already libraries for this, most notably https://github.com/faheel/BigInt, however that makes use of strings with a base-10 representation to perform arithmetic.
This new implementation makes use of a dynamic array of uint32_t, essentially allowing us to perform computations in base 2^32.

## TODO
* Subtraction
* Division
* Modulo
* Bitwise operations ??
* Many more fun things
