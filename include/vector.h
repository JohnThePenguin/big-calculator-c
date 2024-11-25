/*
    File: vector.h
    Description:
        This file contains the definition of
        the Vector struct (like c++) and its functions.
*/

#ifndef VECTOR_H
#define VECTOR_H

/*
    Vector structure
    value - char array of elements
    size - current use size of array
    allocated - current allocated size of array
*/
struct Vector {
    char* value;
    int size;
    int allocated;
};

typedef struct Vector* VecPointer;

/*
    Function creates vector
    @return pointer to vector
*/
VecPointer createVector();

/*
    Function deletes vector
    @param v - pointer to vector
    @return void
*/
void deleteVector(VecPointer* v);

/*
    Function copies vector b to vector destination 
    and deletes original value of destination vector
    @param destination - pointer to vector
    @param b - pointer to vector
    @return void
*/
void copyVector(VecPointer* destination, VecPointer b);

/*
    Function rewrites vector a to vector destination 
    and deletes original value of destination vector and second vector
    @param destination - pointer to vector
    @param a - pointer to vector
    @return void
*/
void rewriteVector(VecPointer* destination, VecPointer* a);

/*
    Function sets vector size
    @param v - pointer to vector
    @param size - new size of vector as integer
    @return void
*/
void setVectorSize(VecPointer v, int size);

/*
    Function pushes char element to the end of vector
    and resizes vector if needed
    @param v - pointer to vector
    @param element - char element to be pushed
    @return void
*/
int pushVector(VecPointer v, char element);

/*
    Function pops char element from the end of vector
    @param v - pointer to vector
    @return current size of vector
*/
int popVector(VecPointer v);

/*
    Function clears vector's array
    @param v - pointer to vector
    @return void
*/
void emptyVector(VecPointer v);

/*
    Function prints vector's array separated by space
    @param v - pointer to vector
    @return void
*/
void printVector(VecPointer v);

#endif