#include "tstring.h"
#include <vector>
#include <deque>
#include <list>
#include <chrono>
#include <iostream>
#include <iomanip>

using Clock = std::chrono::steady_clock;

constexpr const char* SAMPLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";   // napis wstawiany do kontenerów

// --------------------------------------------------------------
// pomocnicza konwersja do milisekund
// --------------------------------------------------------------
static double millis(Clock::time_point t0, Clock::time_point t1)
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
}

// ============================== INSERT ============================
// -------------- VECTOR --------------
double insert_back_vector(std::size_t reps)
{
    std::vector<TString> v; v.reserve(reps);
    auto t0 = Clock::now();
    for (std::size_t i = 0; i < reps; ++i) v.emplace_back(SAMPLE);
    auto t1 = Clock::now();
    return millis(t0, t1);
}

double insert_front_vector(std::size_t reps)
{
    std::vector<TString> v; v.reserve(reps);
    auto t0 = Clock::now();
    for (std::size_t i = 0; i < reps; ++i) v.insert(v.begin(), TString(SAMPLE));
    auto t1 = Clock::now();
    return millis(t0, t1);
}

double insert_middle_vector(std::size_t reps)
{
    std::vector<TString> v; v.reserve(reps);
    auto t0 = Clock::now();
    for (std::size_t i = 0; i < reps; ++i)
        v.insert(v.begin() + v.size() / 2, TString(SAMPLE));
    auto t1 = Clock::now();
    return millis(t0, t1);
}

// -------------- DEQUE ---------------
double insert_back_deque(std::size_t reps)
{
    std::deque<TString> d;
// kod
}

double insert_front_deque(std::size_t reps)
{
    std::deque<TString> d;
// kod
}

double insert_middle_deque(std::size_t reps)
{
    std::deque<TString> d;
// kod
}

// --------------- LIST ---------------
double insert_back_list(std::size_t reps)
{
    std::list<TString> l;
// kod
}

double insert_front_list(std::size_t reps)
{
    std::list<TString> l;
// kod
}

double insert_middle_list(std::size_t reps)
{
    std::list<TString> l;
// kod
}

// ============================== ERASE =============================
// -------------- VECTOR --------------
double erase_back_vector(std::size_t reps)
{
    std::vector<TString> v(reps, TString(SAMPLE));
// kod
}

double erase_front_vector(std::size_t reps)
{
    std::vector<TString> v(reps, TString(SAMPLE));
// kod
}

double erase_middle_vector(std::size_t reps)
{
    std::vector<TString> v(reps, TString(SAMPLE));
// kod
}

// -------------- DEQUE ---------------
double erase_back_deque(std::size_t reps)
{
    std::deque<TString> d(reps, TString(SAMPLE));
// kod
}

double erase_front_deque(std::size_t reps)
{
    std::deque<TString> d(reps, TString(SAMPLE));
// kod
}

double erase_middle_deque(std::size_t reps)
{
    std::deque<TString> d(reps, TString(SAMPLE));
// kod
}

// --------------- LIST ---------------
double erase_back_list(std::size_t reps)
{
    std::list<TString> l(reps, TString(SAMPLE));
// kod
}

double erase_front_list(std::size_t reps)
{
    std::list<TString> l(reps, TString(SAMPLE));
// kod
}

double erase_middle_list(std::size_t reps)
{
    std::list<TString> l(reps, TString(SAMPLE));
// kod
}

// ----------------------------- MAIN -------------------------------
int main()
{
    // liczba powtórzeń 
    std::size_t N = 100'000;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "N = " << N << "\n\n";

    // ====================== INSERT ======================
    std::cout << "=== INSERT ===\n";
    std::cout << "vector back   : " << insert_back_vector(N)   << " ms\n";
    std::cout << "vector front  : " << insert_front_vector(N)  << " ms\n";
    std::cout << "vector middle : " << insert_middle_vector(N) << " ms\n\n";

    std::cout << "deque  back   : " << insert_back_deque(N)    << " ms\n";
    std::cout << "deque  front  : " << insert_front_deque(N)   << " ms\n";
    std::cout << "deque  middle : " << insert_middle_deque(N)  << " ms\n\n";

    std::cout << "list   back   : " << insert_back_list(N)     << " ms\n";
    std::cout << "list   front  : " << insert_front_list(N)    << " ms\n";
    std::cout << "list   middle : " << insert_middle_list(N)   << " ms\n\n";

    // ====================== ERASE ======================
    std::cout << "=== ERASE ===\n";
    std::cout << "vector back   : " << erase_back_vector(N)    << " ms\n";
    std::cout << "vector front  : " << erase_front_vector(N)   << " ms\n";
    std::cout << "vector middle : " << erase_middle_vector(N)  << " ms\n\n";

    std::cout << "deque  back   : " << erase_back_deque(N)     << " ms\n";
    std::cout << "deque  front  : " << erase_front_deque(N)    << " ms\n";
    std::cout << "deque  middle : " << erase_middle_deque(N)   << " ms\n\n";

    std::cout << "list   back   : " << erase_back_list(N)      << " ms\n";
    std::cout << "list   front  : " << erase_front_list(N)     << " ms\n";
    std::cout << "list   middle : " << erase_middle_list(N)    << " ms\n";
}

