# Big C Calculator
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
```git clone https://github.com/JohnThePenguin/big-calculator-c```

Skompiluj
```mkdir build```
```make```

Uruchom [plik wejściowy] [? plik wyjściowy]
```./build/main sample.txt```

##### Wyjście programu
Program na wyjście standardowe wypisuje informacje o obecnych działaniach oraz błędach.
Do pliku, wypisywane są jednynie wejścia i wyniki działań w odpowiednim formacie.


### Błędy
Program wykrywa błędy w wejściu takie jak
- Nie istniejący plik z wejściem lub wyjściem
- Zły format pierwszej liniki segmentu
- Zła liczba dla podanego systemu liczbowego
- Zła baza systemu liczbowego
- Błędy typu dzielenie przez 0
- Problemy z alokacją pamięci



