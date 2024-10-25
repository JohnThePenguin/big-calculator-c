#include "numbers_chars.h"

int num(char c){
    if(c <= '9') return c - '0';
    else return c - 'A' + 10;
}

char chr(int i){
    return chars[i];
}