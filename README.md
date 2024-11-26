# Big C Calculator (Linux / Windows)
---
Program wykonujący obliczenia na własnych strukturach.
Dostępne są obliczenia na możliwie nieskończenie dużych liczbach w dowolnych systemach liczbowych, 
których ograniczeniami są złożolności wykożystancyh algorytmów.
Program przetwarza pliki w zgodnym dla siebie formacie, sprawdzając przy tym ich poprawność.
Do wyboru jest kilka operacji:
- a + b (O = L)
- a * b (O = L^2)
- a / b (O = L^2)
- a % b (O = L^2)
- a ^ b (O = log2(b) * ?)
  
gdzie l to liczba znaków liczby


### Uruchomienie
---
Pobierz repozytorium
```
git clone https://github.com/JohnThePenguin/big-calculator-c
```

Skompiluj
```
mkdir build
make
```

Uruchom [plik wejściowy] [? plik wyjściowy]
```
./build/main sample.txt
```

##### Wyjście programu
Program na wyjście standardowe wypisuje informacje o obecnych działaniach oraz błędach.
Do pliku, wypisywane są jednynie wejścia i wyniki działań w odpowiednim formacie.


### Błędy
---
Program wykrywa błędy w wejściu takie jak
- Nie istniejący plik z wejściem lub wyjściem
- Zły format pierwszej liniki segmentu
- Zła liczba dla podanego systemu liczbowego
- Zła baza systemu liczbowego
- Błędy typu dzielenie przez 0
- Problemy z alokacją pamięci

### Implementacja
---
Podstawą programu są dwie struktury:
##### Vector
```c
struct Vector {
    char* value;
    int size;
    int allocated;
};
```
będący odpowiednią strukturą dla ```std::vector``` z c++, oraz

##### Number
```c
struct Number {
    VecPointer number;
    int system;
};
```

Obie struktury są żadko przekazywane jako wartości, dlatego w kodzie wszędzie występują dwa ```typedef```:
```c
typedef struct Number* NumPointer;
typedef struct Vector* VecPointer;
```
Wszystkie operacje w wyższej warstwie programu są wykonywane właśnie na nich.

##### Obliczenia
Obliczenia zazwyczaj przyjmują dwa ```NumPointer``` i zwracają nowy obiekt.
Złożolności operacji były już opisane wyżej. Poza potęgowaniem, zostały użyte algorytmy primitywne, taki jakich uczymy się w szkole podstawowej. Potęgowanie zostało zaimplementowane algorytmem szybkiego potęgowania, tzn. dzielenia wykładnika na dwie równe części. Program jest w stanie w ~20s obliczyć 2^(500k) przy kompilacji z O3.

### Problemy, podsumowanie
---
Momentami struktura projektu się rozrastała i stawała się co raz mniej przejrzysta, dlatego został zastosowany duży podział kodu na wiele plików. Również problemem był nieporządek z stworzonymi objektami, który został usprawniony przez funkcje takie jak ```rewriteNumber```, pozwalający nadpisywać stare objekty nowymi, bez niekontrolowanych strat pamięci.
Pewnego razu, możnaby wprowadzić optymalizacje algorytmów używając np. FFT dla mnożenia.
