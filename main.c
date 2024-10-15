#include <stdio.h>
#include "numbers.h"

int main(){
    struct Number* num = createNumber("4096", 4);
    printNumber(num);   
    setNumber(num, "909012423", 9);
    printNumber(num);

    struct Number* Copy = copyNumber(createNumber("", 0), num);

    printNumber(Copy);
}