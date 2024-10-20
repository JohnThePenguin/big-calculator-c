#include <stdio.h>
#include "numbers.h"

int main(){
    struct Number* one = createNumber("9800123", 7);
    struct Number* two = createNumber("210", 3);

    // printNumber(multiplyNumbers(two, one));
    // printNumber(addNumbers(two, one));

    int divide = divideManualNumbers(one->number, two->number, 0, 6);
    printf("%d\n", divide);
    cleanZeros(one);
    printNumber(one);

    return 0;

    divide = subtractNumbers(one->number, two->number, 0, 3);
    printf("%d\n", divide);
    printNumber(one);


    divide = subtractNumbers(one->number, two->number, 0, 3);
    printf("%d\n", divide);
    printNumber(one);


    divide = subtractNumbers(one->number, two->number, 0, 3);
    printf("%d\n", divide);
    cleanZeros(one);
    printNumber(one);

    divide = subtractNumbers(one->number, two->number, 0, 3);
    printf("%d\n", divide);
    printNumber(one);
}