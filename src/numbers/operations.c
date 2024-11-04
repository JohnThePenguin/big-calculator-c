#include "numbers_core.h"
#include "numbers_operations.h"

NumPointer addNumbers(NumPointer a, NumPointer b){
    VecPointer result = createVector();
    NumPointer final = createNumber(-1);

    int i = 0;
    int temp = 0;

    for(i = 0; i < max(a->number->size, b->number->size); i++){
        if(i < a->number->size)
            temp += a->number->value[i];

        if(i < b->number->size)
            temp += b->number->value[i];
        
        pushVector(result, temp % 10);
        temp /= 10;
    }

    if(temp > 0)
        pushVector(result, temp);

    
    setNumberProperyValue(final, result);
    return final;
}

NumPointer multiplyNumbers(NumPointer a, NumPointer b){
    VecPointer result = createVector();
    NumPointer final = createNumber(-1);

    int i = 0;
    int j = 0;
    size_t rest = 0; /*originally long long (ansi)*/
    size_t max_size = max(a->number->size, b->number->size);

    for(i = 0; i < 2 * max_size; i++){

        for(j = i; j >= 0; j--){

            if((j < a->number->size) && (i - j < b->number->size)){
                rest += (
                    (a->number->value[j]) *
                    (b->number->value[i - j])
                );
            }
        }
        
        pushVector(result, rest % 10);

        rest /= 10;
    }

    setNumberProperyValue(final, result);
    cleanZeros(final);

    return final;
}

int subtractNumbers(VecPointer a, struct Vector *b, int left, int right){
    int i = 0;
    int j = 0;

    if(right - left + 1 < b->size){
        return 0;
    }

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
        if(b->size == i){
            return 1;
        }

        if(a->value[i + left] >= b->value[i]){
            a->value[i + left] -= b->value[i];
        }
        else{
            int j = i + 1;
            while(a->value[j + left] == 0)
                a->value[j++ + left] = 9;

            a->value[j + left]--;
            a->value[i + left] = 10 + a->value[i + left] - b->value[i];
        }
    }

    return 1;
}