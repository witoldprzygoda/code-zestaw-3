#ifndef MACIERZE_H
#define MACIERZE_H

#include <vector>
#include <string>

using Macierz = std::vector<std::vector<double>>;

Macierz wczytaj_macierz(const std::string& nazwa, int& m, int& n);
void zapisz_macierz(const Macierz& macierz, const std::string& nazwa);
Macierz mnoz_macierze(const Macierz& A, const Macierz& B);

#endif // MACIERZE_H
