/*
    File: numbers_system.h
    Description:
        This file contains the declaration of 
        the functions that are used to convert 
        numbers from one system to another.
*/

#ifndef NUMBERS_SYSTEM_H
#define NUMBERS_SYSTEM_H

/* 
    Function converts number to decimal system
    @param a - pointer to number to convert
    @return void
*/
void toDecimalSystem(NumPointer a);

/* 
    Function converts number from decimal system to system passed as argument
    @param a - pointer to number to convert
    @param system - system to convert to as integer
    @return void
*/
void fromDecimalSystem(NumPointer* a, int system);

/* 
    Function sets the system of the number
    @param a - pointer to number to set system
    @param system - system to set as integer
    @return void
*/
void setSystem(NumPointer* a, int system);

/* 
    Function powers the number to the power of the number
    @param a - pointer to number to power
    @param b - pointer to number to power by
    @return system of the number as integer
*/
void powerNumbers(NumPointer* a, NumPointer* n);

/* 
    Function provides both numbers in the system of the number
    @param a - pointer to first number
    @param b - pointer to second number
    @return system of the number as integer
*/
int systemOfTwo(NumPointer a, NumPointer *b);

#endif
