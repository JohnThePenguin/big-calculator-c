#include "numbers_core.h"
#include "numbers_operations.h"
#include "numbers_system.h"

/* Descriptions and comments are in include/numbers_operations.h */

NumPointer addNumbers(NumPointer a, NumPointer b){
    /* Result is helper vector for calculating on */

    VecPointer result = createVector();
    NumPointer final = createNumber(-1);

    /* Make sure, both are in same system */
    int i = 0;
    int temp = 0;
    int system = systemOfTwo(a, &b); 

    /* Simple primary-school-like addition */
    for(i = 0; i < max(a->number->size, b->number->size); i++){
        if(i < a->number->size)
            temp += a->number->value[i];

        if(i < b->number->size)
            temp += b->number->value[i];
        
        pushVector(result, temp % system);
        temp /= system;
    }

    /* "Carry" */
    if(temp > 0)
        pushVector(result, temp);

    /* Rewrite vector to new number */
    setNumberPropertyValue(final, result);
    return final;
}

NumPointer multiplyNumbers(NumPointer a, NumPointer b){
    /* Same schema as addition */
    VecPointer result = createVector();
    NumPointer final = createNumber(-1);

    int i = 0;
    int j = 0;
    size_t rest = 0;
    size_t maxSize = max(a->number->size, b->number->size);
    
    int system = systemOfTwo(a, &b);

    /* Moving in way to calculate one number perfectly, and do not come back */
    /* Multiplied number cannot be longer than 2*maxSize */
    /* "Walking" to describe */
    for(i = 0; (size_t)i < 2 * maxSize; i++){

        for(j = i; j >= 0; j--){

            if((j < a->number->size) && (i - j < b->number->size)){
                rest += (
                    (a->number->value[j]) *
                    (b->number->value[i - j])
                );
            }
        }
        
        pushVector(result, rest % system);

        rest /= system;
    }

    setNumberPropertyValue(final, result);
    cleanZeros(final);

    return final;
}

int subtractNumbers(VecPointer a, struct Vector *b, int system, int left, int right){
    int i = 0;
    int j = 0;

    /* If first number is shorter than second*/
    if(right - left + 1 < b->size){
        return 0;
    }

    /* If in first number exists position bigger than in second*/
    if(right - left + 1 == b->size){
        for(i = b->size - 1; i >= 0; i--){
            if(b->value[i] > a->value[i + left]){
                return 0;
            }
            else if(b->value[i] < a->value[i + left]){
                break;
            }
        }
    }

    for(i = 0; i <= right - left; i++){
        /* No need for going furher, end of b */
        if(b->size == i){ 
            return 1;
        }

        /* If it can be simple substraction, or there is need for more complex*/
        if(a->value[i + left] >= b->value[i]){
            a->value[i + left] -= b->value[i];
        }
        else{
            /* Going to bigger position for making substraction on smaller possible*/
            j = i + 1;
            while(a->value[j + left] == 0)
                a->value[j++ + left] = system - 1;

            a->value[j + left]--;
            a->value[i + left] = system + a->value[i + left] - b->value[i];
        }
    }

    return 1;
}