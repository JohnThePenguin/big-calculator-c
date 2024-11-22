#include "numbers_chars.h"

int num(char c){
    if('0' <= c && c <= '9') return c - '0';
    else if('A' <= c && c <= 'F') return c - 'A' + 10;
    else return 100;
}

char chr(int i){
    const char chars[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
    };

    return chars[i];
}