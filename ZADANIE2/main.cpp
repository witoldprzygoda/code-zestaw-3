#include "bigint.h"
#include <iostream>

int main()
{
    BigInt a("12345678901234567890");
    BigInt b("-987654321");
    BigInt c = a + b;        // dodawanie
    BigInt d = a - BigInt("1");
    BigInt e = -c;           // operator jednoargumentowy –

    std::cout << "a  = " << a << '\n';
    std::cout << "b  = " << b << '\n';
    std::cout << "a+b= " << c << '\n';
    std::cout << "a-1= " << d << '\n';
    std::cout << "-(a+b)= " << e << '\n';
}
