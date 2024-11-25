#include "numbers_chars.h"

/* Descriptions and comments are in include/numbers_chars.h */

/* Table for converting char to int */
const char chars[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

int num(char c){
    if('0' <= c && c <= '9') return c - '0';
    else if('A' <= c && c <= 'F') return c - 'A' + 10;
    else return 100;
}

char chr(int i){
    return chars[i];
}