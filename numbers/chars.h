#ifndef CHARS_H
#define CHARS_H

char chars[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

int num(char c){
    if(c <= '9') return c - '0';
    else return c - 'A' + 10;
}

char chr(int i){
    return chars[i];
}

#endif