#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "vector.h"

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

void printNumber(struct Number* a){
    for(int i = a->number->size - 1; i >= 0; i--){
        printf("%c", a->number->value[i]);
    }
    printf("\n");
}