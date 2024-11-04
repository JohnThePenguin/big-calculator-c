#ifndef NUMBERS_CORE_H
#define NUMBERS_CORE_H

#include "stdio.h"
#include "vector.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

struct Number {
    VecPointer number;
    int system;
};

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

void setNumberProperyValue(NumPointer a, VecPointer v);

void copyNumber(NumPointer* a, NumPointer b);

void deleteNumber(NumPointer* a);

void rewriteNumber(NumPointer* destination, NumPointer* a);

void printNumber(NumPointer a);

void cleanZeros(NumPointer a);

#endif