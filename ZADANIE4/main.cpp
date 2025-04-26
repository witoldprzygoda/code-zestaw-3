#include <iostream>
#include "rsa.h"

int main() {
    int p = 61, q = 53; // przykładowe liczby pierwsze
    auto [pub, priv] = RSA::generujKlucze(p, q);

    int wiadomosc = 65;
    int szyfr = RSA::szyfruj(wiadomosc, pub);
    int odszyfr = RSA::deszyfruj(szyfr, priv);

    std::cout << "Klucz publiczny (e,n): " << pub.e << ", " << pub.n << '\n';
    std::cout << "Klucz prywatny (d,n): " << priv.e << ", " << priv.n << '\n';

    std::cout << "Wiadomosc: " << wiadomosc << '\n';
    std::cout << "Szyfr: " << szyfr << '\n';
    std::cout << "Odszyfrowana: " << odszyfr << '\n';
}
