#ifndef NUMBERS_CORE_H
#define NUMBERS_CORE_H

#include "stdio.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

struct Number;

typedef struct Number* NumPointer;

NumPointer createNumber(int value);

void setNumber(NumPointer a, int value);

void setNumberFromString(
    NumPointer a, 
    const char* 
    value, 
    size_t size, 
    int system
);

NumPointer copyNumber(NumPointer a, NumPointer b);

void deleteNumber(NumPointer a);

void printNumber(NumPointer a);

void cleanZeros(NumPointer a);

#endif