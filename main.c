#include <stdio.h>
#include "numbers.h"

int main(){
    struct Number* one = createNumber("243612", 6);
    struct Number* two = createNumber("5332", 4);

    printNumber(multiplyNumbers(two, one));
    printNumber(addNumbers(two, one));
}