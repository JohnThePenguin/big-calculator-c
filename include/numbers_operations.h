#ifndef NUMBERS_OPERATIONS_H
#define NUMBERS_OPERATIONS_H

NumPointer addNumbers(NumPointer a, NumPointer b);

NumPointer multiplyNumbers(NumPointer a, NumPointer b);

int subtractNumbers(
    VecPointer a, 
    struct Vector *b, 
    int system,
    int left, 
    int right
);

#endif