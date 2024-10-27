#include "numbers_core.h"
#include "numbers_operations.h"
#include "numbers_dividing.h"

int divideManualNumbers(struct Vector* a, struct Vector *b, int left, int right){
    int count = 0;

    while(subtractNumbers(a, b, left, right) == 1){
        while(a->value[right] == 0) right--;
        count++;
    }

    return count;
}

NumPointer normalizeDividedNumber(NumPointer a){
    size_t size = a->number->size;
    for(int i = 0; i < size / 2; i++){
        int t = a->number->value[i];
        a->number->value[i] = a->number->value[size - i - 1];
        a->number->value[size - i - 1] = t;
    }
    cleanZeros(a);
    return a;
}

NumPointer divideNumbers(NumPointer a, NumPointer b){
    if(a->number->size < b->number->size){
        return createNumber(0);
    }

    size_t a_size = a->number->size;
    size_t b_size = b->number->size;

    int left = a_size - 1;
    int right = a_size - 1;

    NumPointer result = createNumber(-1);

    while(left > 0){
        left--;
        while(right - left + 1 < b_size){
            left--;
            pushVector(result->number, 0);
        }

        int count = divideManualNumbers(a->number, b->number, left, right);
        
        pushVector(result->number, count);

        // printf("left: %d, right: %d, divide: %d\n", left, right, count);
        // printNumber(result);
        // printNumber(a);

        while(right > 0 && a->number->value[right] == 0){
            right--;
        }
    }

    cleanZeros(a);
    return normalizeDividedNumber(result);
}