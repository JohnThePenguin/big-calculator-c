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
    struct Number* a = malloc(sizeof(struct Number));
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
    struct Number* copied = memcpy(a, b, sizeof(b));

    if(copied == NULL){
        error("Could not copy Number object");
    }

    return copied;
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

void printNumber(struct Number* a){
    for(int i = a->number->size - 1; i >= 0; i--){
        printf("%c", a->number->value[i] + '0');
    }
    printf("\n");
}