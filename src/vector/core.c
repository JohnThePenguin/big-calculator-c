#include "error.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Descriptions and comments are in include/numbers_systems.h */

VecPointer createVector(){
    VecPointer a = (VecPointer)malloc(sizeof(struct Vector));
    a->size = 0;
    a->allocated = 0;
    a->value = (char*)malloc(2 * sizeof(char));

    if(a->value == NULL){
        error("Could not allocate memory for vector");
    }
    else{
        a->allocated = 2;
    }

    return a;
}

void deleteVector(VecPointer* v){
    if(*v != NULL && v != NULL){
        free((*v)->value);
        free(*v);
        *v = NULL;
    }
}

void copyVector(VecPointer* destination, VecPointer b){
    deleteVector(destination);

    /* Simply copy property by property */
    (*destination) = (VecPointer)malloc(sizeof(struct Vector));
    (*destination)->size = b->size;
    (*destination)->allocated = b->allocated;
    (*destination)->value = (char*)malloc(b->allocated * sizeof(char));

    /* Copy memory from b to destination */
    memcpy(
        (*destination)->value,
        b->value,
        sizeof(char) * b->allocated
    );
}

/* Deletes destination, overwrites what a points to and links a to destination*/
void rewriteVector(VecPointer* destination, VecPointer* a){
    deleteVector(destination);
    *destination = *a;
    *a = NULL;
}

void setVectorSize(VecPointer v, int size){
    if(v->allocated == size){
        return;
    }
    if(v->allocated > size){
        return;
    }
    else{
        v->value = (char*)realloc(v->value, size * sizeof(char));
        
        if(v->value == NULL){
            error("Could not allocate!");
        }   
        else{
            v->allocated = size;
        }
    }
}

/* Pushes new value to error, if array is too small, sets new size */
/* Resizes it to 2*[current size], so complexity is nearly linear */
int pushVector(VecPointer v, char element){
    if(v->allocated == v->size){
        setVectorSize(v, v->size * 2);
    }

    v->value[v->size] = element;
    return ++v->size;   
}

int popVector(VecPointer v){
    if(v->size == 0){
        return -1;
    }
    else{
        return --v->size;
    }
}

void emptyVector(VecPointer v){
    v->size = 0;
}

void printVector(VecPointer v){
    int i = 0;

    if(v == NULL){
        printf("<Given NULL as pointer to Vector>");
    }
    else{
        for(i = v->size - 1; i >= 0; i--){
            printf("%c ", v->value[i]);
        }
    }
    printf("\n");
}