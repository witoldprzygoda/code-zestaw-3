// tests/test_mnozenie.cpp – testy Google Test dla mnożenia macierzy
#include "../macierze.h"
#include <gtest/gtest.h>

// test sprawdzający mnożenie macierzy 2×3 przez 3×2
TEST(MnozenieMacierzyTest, PodstawowyPrzypadek)
{
    Macierz A{{1,2,3},
              {4,5,6}};

    Macierz B{{7,8},
              {9,10},
              {11,12}};

    Macierz oczekiwana{{58,64},
                       {139,154}};

    Macierz wynik = mnoz_macierze(A, B);
    EXPECT_EQ(wynik, oczekiwana);
}

// test sprawdzający mnożenie macierzy jednostkowej
TEST(MnozenieMacierzyTest, MacierzJednostkowa)
{
    Macierz A{{1,0},{0,1}};
    Macierz B{{5,6},{7,8}};
    
    Macierz wynik = mnoz_macierze(A, B);
    EXPECT_EQ(wynik, B); // A * B = B
}

// test sprawdzający mnożenie macierzy zerowej
TEST(MnozenieMacierzyTest, MacierzZerowa)
{
    Macierz A{{0,0},{0,0}};
    Macierz B{{1,2},{3,4}};

    Macierz oczekiwana{{0,0},{0,0}};

    Macierz wynik = mnoz_macierze(A, B);
    EXPECT_EQ(wynik, oczekiwana);
}
