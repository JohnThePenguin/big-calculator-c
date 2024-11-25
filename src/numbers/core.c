#include "vector.h"
#include "error.h"

#include "numbers_core.h"
#include "numbers_chars.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Descriptions and comments are in include/numbers_core.h */

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

/* Function:
    1) deletes current vector property
    2) sets property to other pointer
*/
void setNumberPropertyValue(NumPointer a, VecPointer v){
    deleteVector(&(a->number));
    a->number = v;
}

/* Function:
    1) deletes destination
    2) creates new empty destination number
    3) copies second number using its properties
*/
void copyNumber(NumPointer* destination, NumPointer b){
    deleteNumber(destination);

    (*destination) = createNumber(-1);
    (*destination)->system = b->system;

    copyVector(&((*destination)->number), b->number);
}

void deleteNumber(NumPointer* a){
    /* If object exists, delete its number object and self*/
    if(*a != NULL && a != NULL){
        deleteVector(&((*a)->number));
        free(*a);
        *a = NULL;
    }
}

/* Deletes destination and simply links object to destination */
void rewriteNumber(NumPointer* destination, NumPointer a){
    deleteNumber(destination);
    *destination = a;
}

int readIntFromNumber(NumPointer a){
    int size = a->number->size;
    int result = 0;
    int i;

    for(i = size - 1; i >= 0; i--){
        result*= a->system;
        result += a->number->value[i];
    }

    return result;
}

void printNumber(NumPointer a){
    int i = 0;

    /* Notify, if number object does not exits */
    if(a == NULL){
        printf("<Given NULL as pointer to Number>");
    }
    else{

        /* Number is in big-endian, going from back to front */
        for(i = a->number->size - 1; i >= 0; i--){
            printf("%c", chr(a->number->value[i]));
        }
    }
    printf("\n");
}

void cleanZeros(NumPointer a){

    /* While number is not empty and first element is 0, pop number */
    while(a->number->size > 1 &&
        a->number->value[a->number->size - 1] == 0){
        
        popVector(a->number);
    }
}