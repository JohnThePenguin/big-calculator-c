#include "numbers_core.h"
#include "numbers_operations.h"
#include "numbers_dividing.h"
#include "numbers_system.h"

/* Descriptions and comments are in include/numbers_systems.h */

void toDecimalSystem(NumPointer a){
    int i = 0;

    NumPointer power = createNumber(1);
    NumPointer system = createNumber(a->system);
    NumPointer result = createNumber(0);
    NumPointer lastDigit = NULL;
    NumPointer multiplication = NULL;


    for(i = 0; i < a->number->size; i++){

        if(a->number->value[i] > 0){
            lastDigit = createNumber(a->number->value[i]);
            multiplication = multiplyNumbers(power, lastDigit);

            /* Add current digit multiplied by power to result */ 
            rewriteNumber(&result, addNumbers(result, multiplication));

            deleteNumber(&lastDigit);
            deleteNumber(&multiplication);
        }

        /* Multiply power by system */
        rewriteNumber(&power, multiplyNumbers(power, system));
    }

    copyVector(&(a->number), result->number);
    a->system = 10;

    deleteNumber(&power);
    deleteNumber(&system);
    deleteNumber(&result);
}

void fromDecimalSystem(NumPointer* a, int system){
    VecPointer result = createVector();
    NumPointer devisor = createNumber(system);
    NumPointer division = NULL;

    /* Until a is 0 */
    while((*a)->number->size > 1 || (*a)->number->value[0] > 0){

        /* When deviding, a is saved rest of division */
        division = divideNumbers(*a, devisor);

        /* Adding rest, rest is not bigger than 16, so we can consider 2 digits*/
        if((*a)->number->size == 1){
            pushVector(result, (*a)->number->value[0]);
        }
        else{
            pushVector(result, (*a)->number->value[0] + 10 * (*a)->number->value[1]);
        }

        rewriteNumber(a, division);
    }

    copyVector(&((*a)->number), result);
    (*a)->system = system;

    deleteVector(&result);
    deleteNumber(&devisor);
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

void powerNumbers(NumPointer* a, NumPointer* n){
    int i = 0;
    NumPointer result = createNumber(1);

    /* Convert number to power by to base 2 for splitting calculations */
    setSystem(n, 2);

    /* Using fast-power algorithm */
    /* Instead of recursion, using 2-base breakdowns */
    for(i = (*n)->number->size - 1; i >= 0; i--){

        rewriteNumber(&result, multiplyNumbers(result, result));

        if((*n)->number->value[i] == 1){
            rewriteNumber(&result, multiplyNumbers(result, *a));
        }
    }

    rewriteNumber(a, result);
}

int systemOfTwo(NumPointer a, NumPointer *b){
    if(a->system != (*b)->system){
        setSystem(b, a->system);
    }

    return a->system;
}