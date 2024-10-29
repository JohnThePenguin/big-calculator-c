#include "error.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if(*v != NULL){
        free((*v)->value);
        free(*v);
        *v = NULL;
    }
}

void copyVector(VecPointer* destination, VecPointer b){
    deleteVector(destination);

    (*destination) = (VecPointer)malloc(sizeof(struct Vector));
    (*destination)->size = b->size;
    (*destination)->allocated = b->allocated;
    (*destination)->value = (char*)malloc(b->allocated * sizeof(char));

    memcpy(
        (*destination)->value,
        b->value,
        sizeof(char) * b->allocated
    );
}

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