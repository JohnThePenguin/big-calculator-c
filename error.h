#include <stdio.h>

void error(const char* s){
    printf("Error occurred\n: %s", s);
    exit(0x0);
}