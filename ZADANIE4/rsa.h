#ifndef RSA_H
#define RSA_H

#include <utility>

struct KluczRSA {
    int e;   // wykladnik
    int n;   // modul
};

class RSA {
public:
    // Generuje klucze (publiczny i prywatny)
    static std::pair<KluczRSA, KluczRSA> generujKlucze(int p, int q);

    // szyfrowanie/deszyfrowanie
    static int szyfruj(int msg, const KluczRSA& klucz);
    static int deszyfruj(int szyfr, const KluczRSA& klucz);

private:
    // ewentualne metody prywatne
};

#endif // RSA_H
