#ifndef BIGINT_H
#define BIGINT_H

#include <string>
#include <iostream>

class BigInt {
public:
    // konstruktory

    /* operatory jednoargumentowe */
    BigInt  operator+() const;   //  +x
    BigInt  operator-() const;   //  -x

    /* operatory dwuargumentowe */
    friend BigInt operator+(const BigInt& a, const BigInt& b);
    friend BigInt operator-(const BigInt& a, const BigInt& b);

    /* wypisywanie */
    friend std::ostream& operator<<(std::ostream& os, const BigInt& x);

private:
    int         znak { 1 };          // 1 – dodatnia, -1 – ujemna
    std::string wartosc { "0" };     // cyfry bez znaku


};

#endif // BIGINT_H
