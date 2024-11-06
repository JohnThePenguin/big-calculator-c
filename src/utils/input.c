#include "input.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *inputFile;

void openFile(const char* c){
    char ch;
    size_t size;

    inputFile = fopen(c, "r");

    if(inputFile == NULL){
        error("File \"%s\" cannot be opened \n");
    }

    size = getFileSize();
    printf("Reading file, size: %ld b\n\n", size);

    while((ch = fgetc(inputFile)) != EOF){
        printf("%c", ch);
    }
}

size_t getFileSize(){
    size_t size;
    fseek(inputFile, 0, SEEK_END);
    size = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    return size;
}

struct InputResponse handleSegment(){
    struct InputResponse a = {
        Calculation,
        0, 
        0, 
        0,
        NULL,
        ""
    };
    return a;
}

char getLineWithContent(){
    return 'a';
}
