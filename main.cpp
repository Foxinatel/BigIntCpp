#include "headers.hpp"

#include <iostream>
#include <vector>

int main() {
    BigInt a {"123456"};
    BigInt b {"5678"};
    BigInt c {a};
    std::cout << ' ' << (a+2) << ' '<< b << ' '<< c+2 << ' ' << (a + "12345");
}