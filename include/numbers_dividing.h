/*
    File: numbers_dividing.h
    Description: 
        This file contains definitions of 
        functions for dividing numbers
*/

#ifndef NUMBERS_DIVIDING_H
#define NUMBERS_DIVIDING_H

/* 
    Function divides numbers by substraction
    @param a - number pointer
    @param b - number pointer
    @param system - number system as integer
    @param left - left offset of digits in number as integer
    @param right - right offset of digits in number as integer
    @return division result as integer
*/
int divideManualNumbers(
    VecPointer a, 
    struct Vector *b, 
    int system,
    int left, 
    int right
);

/* 
    Function normalizes number after division (reverse and leading zeros)
    @param a - number pointer
    @return pointer to number
*/
NumPointer normalizeDividedNumber(NumPointer a);

/* 
    Function divides numbers and saves the rest in first number
    @param a - number pointer
    @param b - number pointer
    @return result of division as pointer to number
*/
NumPointer divideNumbers(NumPointer a, NumPointer b);

#endif