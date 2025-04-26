#include <gtest/gtest.h>
#include "../rsa.h"

TEST(RSATest, SzyfrowanieDeszyfrowanie) {
    int p = 61, q = 53;
    auto [pub, priv] = RSA::generujKlucze(p, q);

    int msg = 42;
    int szyfr = RSA::szyfruj(msg, pub);
    int odszyfrowana = RSA::deszyfruj(szyfr, priv);

    EXPECT_EQ(odszyfrowana, msg);
}

TEST(RSATest, PotegowanieModulo) {
    KluczRSA pub{17, 3233};
    KluczRSA priv{2753, 3233};

    int szyfr = RSA::szyfruj(65, pub);
    EXPECT_EQ(szyfr, 2790);

    int odszyfrowana = RSA::deszyfruj(szyfr, priv);
    EXPECT_EQ(odszyfrowana, 65);
}

TEST(RSATest, GeneracjaKluczy) {
    auto [pub, priv] = RSA::generujKlucze(17, 11);
    EXPECT_EQ(pub.n, 187);
    EXPECT_EQ(priv.n, 187);
    EXPECT_NE(pub.e, priv.e);
}
