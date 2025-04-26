#include "tstring.h"
#include <iostream>
#include <cstring>

using namespace std;



TString::TString(const char* s) {
    if (s != nullptr) {
        len = strlen(s);
        ptr = new char[len+1]; // +1 bo na koncu jest jeszcze \0 konczące literał napisowy
        strcpy(ptr, s);
    }
#ifdef DEBUG
    cout << "TString c-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
#endif
    ++licznik;
}

TString::~TString() {
#ifdef DEBUG
    cout << "TString d-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
#endif
    delete [] ptr;
    --licznik;
}

// --------------------------------------------------------------
// KOPIUJĄCY C-TOR
// --------------------------------------------------------------
TString::TString(const TString& s)
    : len{s.len}, ptr{nullptr}
{
    if (len) {
        ptr = new char[len + 1];
        strcpy(ptr, s.ptr);
    }
#ifdef DEBUG
    cout << "TString cc-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
#endif
    ++licznik;
}

// --------------------------------------------------------------
// OPERATOR= (kopiujący)
// --------------------------------------------------------------
TString& TString::operator=(const TString& s)
{
    if (this != &s) {               // ochrona przed samoprzydziałem
        delete[] ptr;
        ptr = nullptr;
        len = s.len;

        if (len) {
            ptr = new char[len + 1];
            strcpy(ptr, s.ptr);
        }
#ifdef DEBUG
        cout << "TString copy operator=: [" << (ptr ? ptr : "pusty") << "]" << endl;
#endif
    }
    return *this;
}

// --------------------------------------------------------------
// PRZENOSZĄCY C-TOR
// --------------------------------------------------------------
TString::TString(TString&& s) 
    : len{s.len}, ptr{s.ptr}
{
    s.len = 0;
    s.ptr = nullptr;

#ifdef DEBUG
    cout << "TString move c-tor: [" << (ptr ? ptr : "pusty") << "]" << endl;
#endif
    ++licznik;
}

// --------------------------------------------------------------
// OPERATOR= (przenoszący)
// --------------------------------------------------------------
TString& TString::operator=(TString&& s) 
{
    if (this != &s) {               // ochrona przed samoprzydziałem
        delete[] ptr;

        len = s.len;
        ptr = s.ptr;

        s.len = 0;
        s.ptr = nullptr;

#ifdef DEBUG
        cout << "TString move operator=: [" << (ptr ? ptr : "pusty") << "]" << endl;
#endif
    }
    return *this;
}
