#include <stdlib.h>
#include <stdio.h>

#include "error.h"

int endOfFile = SUCCESS;

void error(const char* s){
    printf("Error occurred\n: %s", s);
    exit(0x0);
}

void exitProcess(int code){
    _exit(code);
}