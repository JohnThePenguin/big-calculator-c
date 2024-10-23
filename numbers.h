#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chars.h"
#include "vector.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

struct Number;

typedef struct Number* NumPointer;

void setNumber(NumPointer a, int value);
NumPointer createNumber(int value);

struct Number {
    struct Vector* number;
    int system;
};

NumPointer createNumber(int value){
    NumPointer a = (NumPointer)malloc(sizeof(struct Number));
    a->number = createVector();
    a->system = 10;

    pushVector(a->number, 0);
    setNumber(a, value);

    return a;
}

void setNumber(NumPointer a, int value){
    emptyVector(a->number);
    if(value == -1){
        return;
    }

    do{
        pushVector(a->number, value % 10);
    }while(value /= 10);
}

void setNumberFromString(NumPointer a, const char* value, size_t size, int system){
    emptyVector(a->number);
    for(int i = size - 1; i >= 0; i--){
        pushVector(a->number, num(value[i]));
    }
    a->system = system;
}

NumPointer copyNumber(NumPointer a, NumPointer b){
    NumPointer copied = (NumPointer)memcpy(a, b, sizeof(b));

    if(copied == NULL){
        error("Could not copy Number object");
    }

    return copied;
}

void deleteNumber(NumPointer a){
    deleteVector(a->number);
    free(a);
    a = NULL;
}

void printNumber(NumPointer a){
    for(int i = a->number->size - 1; i >= 0; i--){
        printf("%c", chr(a->number->value[i]));
    }
    printf("\n");
}

void cleanZeros(NumPointer a){
    while(a->number->value[a->number->size - 1] == 0){
        popVector(a->number);
    }
}

NumPointer addNumbers(NumPointer a, NumPointer b){
    struct Vector* result = createVector();

    int temp = 0;
    for(int i = 0; i < max(a->number->size, b->number->size); i++){
        if(i < a->number->size)
            temp += a->number->value[i];

        if(i < b->number->size)
            temp += b->number->value[i];
        
        pushVector(result, temp % 10);
        temp /= 10;
    }

    if(temp > 0)
        pushVector(result, temp);

    NumPointer final = createNumber(-1);
    final->number = result;
    return final;
}

NumPointer multiplyNumbers(NumPointer a, NumPointer b){
    struct Vector* result = createVector();

    long long rest = 0;
    size_t max_size = max(a->number->size, b->number->size);

    for(int i = 0; i < 2 * max_size; i++){

        for(int j = i; j >= 0; j--){

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

    NumPointer final = createNumber(-1);
    final->number = result;
    cleanZeros(final);

    return final;
}

int subtractNumbers(struct Vector* a, struct Vector *b, int left, int right){
    if(right - left + 1 < b->size){
        return 0;
    }

    if(right - left + 1 == b->size){
        for(int i = b->size - 1; i >= 0; i--){
            if(b->value[i] > a->value[i + left]){
                return 0;
            }
            else if(b->value[i] < a->value[i + left]){
                break;
            }
        }
    }

    for(int i = 0; i <= right - left; i++){
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