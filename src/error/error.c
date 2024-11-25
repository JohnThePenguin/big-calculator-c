#include <stdlib.h>
#include <stdio.h>

#include "error.h"
#include "input.h"
#include "output.h"

int endOfFile = SUCCESS;

void error(const char* s){
    printf("Error occurred:\n %s\n", s);
    exitProcess(0x0);
}

void exitProcess(int code){
    closeInputFile();
    closeOutputFile();
    exit(code);
}