#ifndef VECTOR_H
#define VECTOR_H

struct Vector {
    char* value;
    int size;
    int allocated;
};

typedef struct Vector* VecPointer;

VecPointer createVector();

void deleteVector(VecPointer* v);

void copyVector(VecPointer* destination, VecPointer b);

void rewriteVector(VecPointer* destination, VecPointer* a);

void setVectorSize(VecPointer v, int size);

int pushVector(VecPointer v, char element);

int popVector(VecPointer v);

void emptyVector(VecPointer v);

void printVector(VecPointer v);

#endif