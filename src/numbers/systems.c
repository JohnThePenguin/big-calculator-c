#include "numbers_core.h"
#include "numbers_operations.h"
#include "numbers_dividing.h"
#include "numbers_system.h"

void toDecimalSystem(NumPointer a){
    int i = 0;

    NumPointer power = createNumber(1);
    NumPointer system = createNumber(a->system);
    NumPointer result = createNumber(0);
    NumPointer lastDigit = NULL;
    NumPointer multiplication = NULL;

    /* printNumber(a);
    printf("%d\n", a->number->size);
    printf("%c\n", a->number->value[a->number->size - 1] + '0');
    */

    for(i = 0; i < a->number->size; i++){

        if(a->number->value[i] > 0){
            lastDigit = createNumber(a->number->value[i]);
            multiplication = multiplyNumbers(power, lastDigit);
        
            rewriteNumber(&result, addNumbers(result, multiplication));

            deleteNumber(&lastDigit);
            deleteNumber(&multiplication);
        }

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

    while((*a)->number->size > 1 || (*a)->number->value[0] > 0){
        division = divideNumbers(*a, devisor);

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

    setSystem(n, 2);

    for(i = (*n)->number->size - 1; i >= 0; i--){
        /*
        printf("\t%c\n", (n->number->value[i] + '0'));
        printNumber(result);
        */

        rewriteNumber(&result, multiplyNumbers(result, result));

        if((*n)->number->value[i] == 1){
            rewriteNumber(&result, multiplyNumbers(result, *a));
        }
    }

    rewriteNumber(a, result);
}

int systemOfTwo(NumPointer a, NumPointer *b){
    if(a->system != (*b)->system){
        printf("Comparing: \n");
        printNumber(a);
        printNumber(*b);
        printf("%d %d\n", a->system, (*b)->system);

        setSystem(b, a->system);
    }

    return a->system;
}