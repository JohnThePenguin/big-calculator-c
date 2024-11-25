#ifndef INPUT_H
#define INPUT_H

#include "numbers_core.h"
#include "error.h"

enum OperationType {
    Calculation = 0,
    SystemChange = 1
};

struct InputResponse{
    enum OperationType type;
    int systemIn;
    int systemOut;
    char operation;
};

extern int inputError;

void openInputFile(int argc, char* argv[]);

void closeInputFile();

size_t getFileSize();

int goToNonWhiteCharacter();

NumPointer readNumber(int system);

NumPointer readNextArgument(int system);

struct InputResponse handleSegment();

void skipCurrentSegment();

struct InputResponse getCalculationSegment(char first);

struct InputResponse getSystemChangeSegment(char first);

struct InputResponse handleInputError(const char* message, int errorCode);

#endif