#include "numbers_core.h"
#include "numbers_operations.h"
#include "numbers_dividing.h"
#include "numbers_system.h"

void toDecimalSystem(NumPointer a){
    int i = 0;

    NumPointer power = createNumber(1);
    NumPointer system = createNumber(a->system);
    NumPointer result = createNumber(0);

    /* printNumber(a);
    printf("%d\n", a->number->size);
    printf("%c\n", a->number->value[a->number->size - 1] + '0');
    */

    for(i = 0; i < a->number->size; i++){

        if(a->number->value[i] > 0){
            NumPointer lastDigit = createNumber(a->number->value[i]);
            NumPointer multiplication = multiplyNumbers(power, lastDigit);
        
            result = addNumbers(result, multiplication);

            deleteNumber(lastDigit);
            deleteNumber(multiplication);
        }

        power = multiplyNumbers(power, system);
    }

    deleteNumber(power);
    deleteNumber(system);
    /* deleteNumber(a); */

    a->number = result->number;
    a->system = 10;
}

void fromDecimalSystem(NumPointer* a, int system){
    NumPointer devisor = createNumber(system);
    struct Vector* result = createVector();

    while((*a)->number->size > 1 || (*a)->number->value[0] > 0){
        NumPointer b = divideNumbers(*a, devisor);

        /*
        // printNumber(b);
        // printNumber(*a);
        // printf("-----------\n");
        */

        if((*a)->number->size == 1){
            pushVector(result, (*a)->number->value[0]);
        }
        else{
            pushVector(result, (*a)->number->value[0] + 10 * (*a)->number->value[1]);
        }

        /* deleteNumber(a); */
        *a = b;
    }

    (*a)->number = result;
    (*a)->system = system;
}

void setSystem(NumPointer* a, int system){
    if(system == 10){
        toDecimalSystem(*a);
    }
    else if((*a)->system == 10){
        fromDecimalSystem(a, system);
    }
    else{
        toDecimalSystem(*a);
        fromDecimalSystem(a, system);
    }
}