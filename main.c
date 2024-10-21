#include <stdio.h>
#include "numbers.h"

int main(){
    const char first[] = "10495121";
    const char second[] = "892";

    struct Number* one = createNumber("10495121", 8);
    struct Number* two = createNumber("892", 3);

    struct Number* divide = divideNumbers(one, two);

    printf("Dividing:\n");
    printNumber(divide);
    printf("Rest:\n");
    printNumber(one);


    // int divide = subtractNumbers(one->number, two->number, 4, 6);
    // printf("%d\n", divide);
    // printNumber(one);

    // divide = subtractNumbers(one->number, two->number, 0, 3);
    // printf("%d\n", divide);
    // printNumber(one);


    // divide = subtractNumbers(one->number, two->number, 0, 3);
    // printf("%d\n", divide);
    // cleanZeros(one);
    // printNumber(one);

    // divide = subtractNumbers(one->number, two->number, 0, 3);
    // printf("%d\n", divide);
    // printNumber(one);
}