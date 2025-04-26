# Zadanie 1

Cel – zmierzyć czasy (ms) wykonania **N** powtórzeń operacji na obiektach
`TString` w trzech kontenerach standardowych.

╔══════════════╦══════════════════════════╦══════════════════════════╦════════════════════════════════════╗
║ Operacja     ║ vector                   ║ deque                    ║ list                               ║
╠══════════════╬══════════════════════════╬══════════════════════════╬════════════════════════════════════╣
║ insert-koniec║ emplace_back             ║ emplace_back             ║ emplace_back                       ║
║ insert-pocz. ║ insert(begin())          ║ emplace_front            ║ emplace_front                      ║
║ insert-środek║ insert(begin()+size/2)   ║ insert(begin()+size/2)   ║ insert(next(begin(), size/2))      ║
║ erase-koniec ║ pop_back                 ║ pop_back                 ║ pop_back                           ║
║ erase-pocz.  ║ erase(begin())           ║ pop_front                ║ pop_front                          ║
║ erase-środek ║ erase(begin()+size/2)    ║ erase(begin()+size/2)    ║ erase(next(begin(), size/2))       ║
╚══════════════╩══════════════════════════╩══════════════════════════╩════════════════════════════════════╝

Co musisz zrobić
----------------
1. **Uzupełnij** definicje `insert_*` i `erase_*` w `main.cpp`.  
   • Każda funkcja przyjmuje `std::size_t reps` (liczbę powtórzeń)  
     i zwraca czas w milisekundach.  
   • Jako wzór służy pełna definicja `insert_back_vector`.

2. **Wypełnij** plik `wyniki.txt` uzyskanymi czasami.  
   (Brak wyników → obniżona ocena.)

