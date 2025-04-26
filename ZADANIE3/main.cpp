#include "macierze.h"
#include <iostream>
#include <fstream>

int main()
{
    // Wczytaj macierz A
    std::ifstream plikA("macierz_A.txt");
    //std::ifstream plikA("macierz_big_A.txt");
    int m = 0, n = 0;
    plikA >> m >> n;
    Macierz A = wczytaj_macierz("macierz_A.txt", m, n);
    //Macierz A = wczytaj_macierz("macierz_big_A.txt", m, n);
    plikA.close();

    // Wczytaj macierz B
    //std::ifstream plikB("macierz_B.txt");
    std::ifstream plikB("macierz_big_B.txt");
    int n2 = 0, p = 0;
    plikB >> n2 >> p;
    Macierz B = wczytaj_macierz("macierz_B.txt", n2, p);
    //Macierz B = wczytaj_macierz("macierz_big_B.txt", n2, p);
    plikB.close();

    // Mnożenie macierzy
    Macierz C = mnoz_macierze(A, B);

    // Zapisz wynik do pliku
    zapisz_macierz(C, "macierz_C.txt");

    std::cout << "Wynik zapisano do macierz_C.txt\n";
}
