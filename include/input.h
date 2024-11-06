#ifndef INPUT_H
#define INPUT_H

#include "numbers_core.h"

enum OperationType {
    Calculation = 0,
    SystemChange = 1
};

struct InputResponse{
    enum OperationType type;
    int systemIn;
    int systemOut;
    int argCount;
    NumPointer* arguments;
    const char* error;
};


void openFile(const char* c);

size_t getFileSize();

struct InputResponse handleSegment();

#endif