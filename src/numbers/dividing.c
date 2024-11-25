#include "numbers_core.h"
#include "numbers_operations.h"
#include "numbers_dividing.h"

#include "error.h"

/* Descriptions and comments are in include/numbers_diving.h */

/* Function for primitive division by substraction*/
int divideManualNumbers(VecPointer a, struct Vector *b, int system, int left, int right){
    int count = 0;

    /* Loop as long as first number is bigger than second */
    while(subtractNumbers(a, b, system, left, right) == 1){
        while(right && a->value[right] == 0) right--;
        count++;
    }

    return count;
}

/* Reverses and cleans leading zeros */
NumPointer normalizeDividedNumber(NumPointer a){
    int i = 0;
    int size = a->number->size;

    for(i = 0; i < size / 2; i++){
        int t = a->number->value[i];
        a->number->value[i] = a->number->value[size - i - 1];
        a->number->value[size - i - 1] = t;
    }

    cleanZeros(a);
    return a;
}

/* 
    Function implements division using primary-school-like algorithm
    used for calculating on paper with pen
*/
NumPointer divideNumbers(NumPointer a, NumPointer b){
    int a_size = a->number->size;
    int b_size = b->number->size;

    /* Offsets of a number, count of manual division*/
    int left = a_size;
    int right = a_size - 1;
    int count = 0;

    NumPointer result = createNumber(-1);

    if(a->system != b->system){
        deleteNumber(&result);
        error("Different numeric systems in division!");        
    }

    if(a->number->size < b->number->size){
        deleteNumber(&result);
        return createNumber(0);
    }

    if(b->number->size == 1 && b->number->value[0] == 0){
        deleteNumber(&result);
        error("Cannot divide by 0");
    }

    while(left > 0){
        /* Move left offset, to make sure it can contain b */
        left--;
        while(left > 0 && right - left + 1 < b_size){
            left--;
            pushVector(result->number, 0);
        }

        /* Calculate division on current offset - count < system */
        count = divideManualNumbers(a->number, b->number, a->system, left, right);
        
        pushVector(result->number, count);

        /* Move right offset, escaping zeros */
        while(right > 0 && a->number->value[right] == 0){
            right--;
        }
    }

    cleanZeros(a);
    return normalizeDividedNumber(result);
}