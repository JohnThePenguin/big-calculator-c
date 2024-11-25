/*
    File: numbers_chars.h
    Description:
        File containing the definition of the functions 
        that convert numbers to characters and vice versa.
*/

#ifndef NUMBERS_CHARS_H
#define NUMBERS_CHARS_H

/*
    Function that converts a character to a number.
    @param c: character to be converted.
    @return: number corresponding to the character
*/
int num(char c);

/*
    Function that converts a number to a character.
    @param i: number to be converted.
    @return: character corresponding to the number
*/
char chr(int i);

#endif