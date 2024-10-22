#include <stdio.h>
#include "numbers.h"

int main(){
    NumPointer one = createNumber(10495121);
    NumPointer two = createNumber(892);

    NumPointer divide = divideNumbers(one, two);

    printf("Dividing:\n");
    printNumber(divide);
    printf("Rest:\n");
    printNumber(one);


    NumPointer addition = addNumbers(one, two);
    printf("Addition: \n");
    printNumber(addition);

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