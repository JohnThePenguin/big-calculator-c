/* 
    File: numbers_core.h
    Description: 
        This file contains definitions of 
        number structure and 
        its core functions for numbers
*/
    
#ifndef NUMBERS_CORE_H
#define NUMBERS_CORE_H

#include "stdio.h"
#include "vector.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

/* 
    Number structure
    number - vector of digits
    system - number system
*/
struct Number {
    VecPointer number;
    int system;
};

typedef struct Number* NumPointer;

/* 
    Function creates number with integer, decimal value
    If -1 passed as value, number will be empty
    @param value - number value
    @return pointer to number
*/
NumPointer createNumber(int value);

/* 
    Function sets value to integer
    If -1 passed as value, number will be empty
    @param a - number pointer
    @param value - number value as integer
    @return pointer to number
*/
void setNumber(NumPointer a, int value);

/* 
    Function sets value from char array
    @param a - number pointer
    @param value - number value as char array
    @param size - size of char array
    @param system - number system as integer
    @return pointer to number
*/
void setNumberFromString(
    NumPointer a, 
    const char* value, 
    size_t size, 
    int system
);

/* 
    Function sets value from vector
    @param a - number pointer
    @param v - vector pointer
    @return pointer to number
*/
void setNumberPropertyValue(NumPointer a, VecPointer v);


/* 
    Function copies number from second to first number
    and deletes original first number
    @param a - first number double pointer
    @param b - second number pointer
    @return void
*/
void copyNumber(NumPointer* a, NumPointer b);


/* 
    Function deletes number
    @param a - number double pointer
    @return void
*/
void deleteNumber(NumPointer* a);


/* 
    Function rewrites number from second to first number
    and deletes both numbers
    @param destination - first number double pointer
    @param a - second number pointer
    @return void
*/
void rewriteNumber(NumPointer* destination, NumPointer a);

/* 
    Function reads integer from number (must be in decimal system)
    @param a - number pointer
    @return integer
*/
int readIntFromNumber(NumPointer a);

/* 
    Function prints number
    @param a - number pointer
    @return void
*/
void printNumber(NumPointer a);

/* 
    Function clean leading zeros from number
    @param a - number pointer
    @return void
*/
void cleanZeros(NumPointer a);

#endif