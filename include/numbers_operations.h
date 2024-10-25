#ifndef NUMBERS_OPERATIONS_H
#define NUMBERS_OPERATIONS_H

NumPointer addNumbers(NumPointer a, NumPointer b);

NumPointer multiplyNumbers(NumPointer a, NumPointer b);

int subtractNumbers(
    struct Vector* a, 
    struct Vector *b, 
    int left, 
    int right
);

#endif