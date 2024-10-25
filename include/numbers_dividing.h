#ifndef NUMBERS_DIVIDING_H
#define NUMBERS_DIVIDING_H

int divideManualNumbers(
    struct Vector* a, 
    struct Vector *b, 
    int left, 
    int right
);

NumPointer normalizeDividedNumber(NumPointer a);

NumPointer divideNumbers(NumPointer a, NumPointer b);

#endif