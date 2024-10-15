#include <stdio.h>
#include "numbers.h"

int main(){
    struct Number* one = createNumber("4096", 4);
    struct Number* two = createNumber("102400", 6);

    printNumber(addNumbers(one, two));
}