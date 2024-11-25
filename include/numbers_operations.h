/*
    File: numbers_operations.h
    Description: 
        This file contains definitions of 
        number basic operations on numbers
*/

#ifndef NUMBERS_OPERATIONS_H
#define NUMBERS_OPERATIONS_H

/*
    Function adds two numbers
    @param a - first number
    @param b - second number
    @return sum of two numbers
*/
NumPointer addNumbers(NumPointer a, NumPointer b);

/*
    Function multiply two numbers
    @param a - first number
    @param b - second number
    @return multiplication of two numbers
*/
NumPointer multiplyNumbers(NumPointer a, NumPointer b);

/*
    Function subtract two numbers,
    saves result in a
    @param a - first number
    @param b - second number
    @return if a > b then 1 else 0
*/
int subtractNumbers(
    VecPointer a, 
    struct Vector *b, 
    int system,
    int left, 
    int right
);

#endif