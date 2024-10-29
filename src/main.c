#include <stdio.h>
#include "numbers.h"

int main(){
    /* 
    NumPointer one = createNumber(10);
    NumPointer two = createNumber(5);

    NumPointer one = createNumber(90844);
    NumPointer two = createNumber(5);


    fromDecimalSystem(&one, 5);
    printNumber(one);

    NumPointer converted = createNumber(0);
    setNumberFromString(converted, "1B2", 3, 13);
    toDecimalSystem(converted);
    printNumber(converted); 
    */

    int number = 0;
    int system = 10;
    NumPointer one = NULL;

    scanf("%d", &number);
    scanf("%d", &system);

    one = createNumber(number);
    fromDecimalSystem(&one, system);

    printNumber(one);

    /*
    printNumber(one);

    NumPointer divide = divideNumbers(one, two);

    printf("Dividing:\n");
    printNumber(divide);
    printf("Rest:\n");
    printNumber(one);


    NumPointer addition = addNumbers(one, two);
    printf("Addition: \n");
    printNumber(addition);

    NumPointer three = createNumber(0);
    setNumberFromString(three, "111100111101110100101010", 24, 2);

    printNumber(three);
    toDecimalSystem(three);
    printNumber(three);


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
    */

    return 0;
}