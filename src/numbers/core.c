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
    emptyVector(a->number);
    for(int i = size - 1; i >= 0; i--){
        pushVector(a->number, num(value[i]));
    }
    a->system = system;
}

NumPointer copyNumber(NumPointer a, NumPointer b){
    // NumPointer copied = (NumPointer)memcpy(a, b, sizeof(b));

    // if(copied == NULL){
    //     error("Could not copy Number object");
    // }

    error("Function not ready");
    return a;
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
