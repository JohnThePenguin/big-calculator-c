#include "vector.h"
#include "error.h"

#include "numbers_core.h"
#include "numbers_chars.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int i = 0;

    emptyVector(a->number);
    for(i = size - 1; i >= 0; i--){
        pushVector(a->number, num(value[i]));
    }
    a->system = system;
}

void copyNumber(NumPointer* destination, NumPointer b){
    deleteNumber(destination);

    (*destination) = createNumber(-1);
    (*destination)->system = b->system;

    copyVector(&((*destination)->number), b->number);
}

void deleteNumber(NumPointer* a){
    if(*a != NULL){
        deleteVector(&((*a)->number));
        free(*a);
        *a = NULL;
    }
}

void rewriteNumber(NumPointer* destination, NumPointer* a){
    deleteNumber(destination);
    *destination = *a;
    *a = NULL;
}

void printNumber(NumPointer a){
    int i = 0;

    if(a == NULL){
        printf("<Given NULL as pointer to Number>");
    }
    else{
        for(i = a->number->size - 1; i >= 0; i--){
            printf("%c", chr(a->number->value[i]));
        }
    }
    printf("\n");
}

void cleanZeros(NumPointer a){
    while(a->number->size > 1 &&
        a->number->value[a->number->size - 1] == 0){
        
        popVector(a->number);
    }
}
