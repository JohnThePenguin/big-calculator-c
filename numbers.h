#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

struct Number;
void setNumber(struct Number* a, const char* value, size_t size);
struct Number* createNumber(const char* value, size_t size);

struct Number {
    struct Vector* number;
    int system;
};

struct Number* createNumber(const char* value, size_t size){
    struct Number* a = (struct Number*)malloc(sizeof(struct Number));
    a->number = createVector();
    a->system = 10;
    pushVector(a->number, 0);

    if(size) setNumber(a, value, size);

    return a;
}

void setNumber(struct Number* a, const char* value, size_t size){
    emptyVector(a->number);
    for(int i = size - 1; i >= 0; i--){
        pushVector(a->number, value[i] - '0');
    }
}

struct Number* copyNumber(struct Number* a, struct Number* b){
    struct Number* copied = (struct Number*)memcpy(a, b, sizeof(b));

    if(copied == NULL){
        error("Could not copy Number object");
    }

    return copied;
}

void printNumber(struct Number* a){
    for(int i = a->number->size - 1; i >= 0; i--){
        printf("%c", a->number->value[i] + '0');
    }
    printf("\n");
}

void cleanZeros(struct Number* a){
    while(a->number->value[a->number->size - 1] == 0){
        popVector(a->number);
    }
}

struct Number* addNumbers(struct Number* a, struct Number* b){
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

    struct Number* final = createNumber("", 0);
    final->number = result;
    return final;
}

struct Number* multiplyNumbers(struct Number* a, struct Number* b){
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

    struct Number* final = createNumber("", 0);
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

//Not ready
struct Number* divideNumbers(struct Number* a, struct Number* b){
    if(a->number->size < b->number->size){
        return createNumber("0", 1);
    }

    size_t a_size = a->number->size;
    size_t b_size = b->number->size;

    int left = a_size;
    int right = a_size;

    struct Number* result = createNumber("", 0);

    while(1){
        while(right - left + 1 < b_size && right > 0){
            right--;
        }

        int count = divideManualNumbers(a->number, b->number, left, right);
        
        pushVector(result->number, count);


        if(count == 0){
            right--;
            continue;
        }

        while(left > 0 && a->number->value[left] == 0){
            left--;
        }
    }
}