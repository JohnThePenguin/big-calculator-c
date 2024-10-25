#include <stdio.h>
#include <stdlib.h>
#include "../error.h"

struct Vector {
    char* value;
    int size;
    int allocated;
};

struct Vector* createVector(){
    struct Vector* a = (struct Vector*)malloc(sizeof(struct Vector));
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

void deleteVector(struct Vector* v){
    free(v->value);
    free(v);
    v = NULL;
}

void setVectorSize(struct Vector* v, int size){
    if(v->allocated == size){
        return;
    }
    if(v->allocated > size){

    }
    else{
        v->value = (char*)realloc(v->value, size * sizeof(char));
        
        if(v->value == NULL){
            //could not allocate
        }   
        else{
            v->allocated = size;
        }
    }
}

int pushVector(struct Vector* v, char element){
    if(v->allocated == v->size){
        setVectorSize(v, v->size * 2);
    }

    v->value[v->size] = element;
    return ++v->size;   
}

int popVector(struct Vector* v){
    if(v->size == 0){
        return -1;
    }
    else{
        return --v->size;
    }
}

void emptyVector(struct Vector* v){
    v->size = 0;
}

void printVector(struct Vector* v){
    for(int i = v->size - 1; i >= 0; i--){
        printf("%c ", v->value[i]);
    }
    printf("\n");
}