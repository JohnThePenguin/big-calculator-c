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
    pushVector(a->number, '0');

    if(size) setNumber(a, value, size);

    return a;
}

void setNumber(struct Number* a, const char* value, size_t size){
    emptyVector(a->number);
    for(int i = size - 1; i >= 0; i--){
        pushVector(a->number, value[i]);
    }
}

struct Number* copyNumber(struct Number* a, struct Number* b){
    struct Number* copied = memcpy(a, b, sizeof(b));

    if(copied == NULL){
        error("Could not copy Number object");
    }

    return copied;
}

struct Number* addNumbers(struct Number* a, struct Number* b){
    struct Vector* result = createVector();

    int temp = 0;
    for(int i = 0; i < max(a->number->size, b->number->size); i++){
        if(i < a->number->size)
            temp += a->number->value[i] - '0';

        if(i < b->number->size)
            temp += b->number->value[i] - '0';
        
        pushVector(result, '0' + (temp % 10));
        temp /= 10;
    }

    if(temp > 0)
        pushVector(result, '0' + temp);

    struct Number* final = createNumber("", 0);
    final->number = result;
    return final;
}

void printNumber(struct Number* a){
    for(int i = a->number->size - 1; i >= 0; i--){
        printf("%c", a->number->value[i]);
    }
    printf("\n");
}