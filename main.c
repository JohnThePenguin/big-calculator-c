#include <stdio.h>
#include "numbers/systems.h"

int main(){
    NumPointer one = createNumber(3089243);
    NumPointer two = createNumber(314);

    // fromDecimalSystem(&two, 13);
    // printNumber(two);

    // NumPointer converted = createNumber(0);
    // setNumberFromString(converted, "842171", 6, 13);
    // toDecimalSystem(converted);
    // printNumber(converted); 

    // printNumber(one);

    NumPointer divide = divideNumbers(one, two);

    printf("Dividing:\n");
    printNumber(divide);
    printf("Rest:\n");
    printNumber(one);


    // NumPointer addition = addNumbers(one, two);
    // printf("Addition: \n");
    // printNumber(addition);

    // NumPointer three = createNumber(0);
    // setNumberFromString(three, "111100111101110100101010", 24, 2);

    // printNumber(three);
    // toDecimalSystem(three);
    // printNumber(three);


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