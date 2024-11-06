#include <stdio.h>
#include <time.h> 

#include "numbers.h"

int main(){
    clock_t c = clock();
    double secondsTaken;

    NumPointer a = createNumber(2);
    NumPointer n = createNumber(500000);

    powerNumbers(&a, n);
    printNumber(a);

    /* Took 23 seconds to finish - length of about 150K digits */
    /* Numbers matching with WolframAlpha */

    /*
    NumPointer a = createNumber(4070);
    NumPointer b = createNumber(15334);

    /*
    rewriteNumber(&a, &b);

    printNumber(a);
    printNumber(b);

    copyNumber(&b, a);

    printNumber(a);
    printNumber(b);

    deleteNumber(&a);
    deleteNumber(&b);

    */
    
    /*
    VecPointer a = createVector();
    VecPointer b = createVector();

    pushVector(a, '5');
    pushVector(a, '2');
    pushVector(a, '8');
    pushVector(a, '1');


    pushVector(b, 'g');
    pushVector(b, 'u');
    pushVector(b, 'f');

    
    rewriteVector(&a, &b);
    printVector(a);
    printVector(b);

    copyVector(&b, a);

    printVector(a);
    printVector(b);

    deleteVector(&a);
    deleteVector(&b);
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
    /*
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

    */

    /*
    NumPointer a = createNumber(4070);
    NumPointer b = createNumber(15334);
    NumPointer addition = multiplyNumbers(a, b);

    printf("Addition: \n");
    printNumber(addition);

    deleteNumber(&a);
    deleteNumber(&b);
    deleteNumber(&addition);
    */

    /*

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

    c = clock() - c; 
    secondsTaken = ((double)c)/CLOCKS_PER_SEC;
    printf("\nExecuted in total of %f seconds \n", secondsTaken); 

    return 0;
}