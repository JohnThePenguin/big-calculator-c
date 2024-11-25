#include "input.h"
#include "error.h"
#include "numbers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bufferRow = 1;
int bufferColumn = 1;
FILE *inputFile;

int inputError = SUCCESS;

void openInputFile(int argc, char* argv[]){
    size_t size;
    char* fileName;

    if(argc < 2){
        error("Please pass name of input file as first parameter");
    }

    fileName = argv[1];

    printf("Trying to open file for input: %s...\n", fileName);
    inputFile = fopen(fileName, "r");

    if(inputFile == NULL){
        printf("File \"%s\" cannot be opened \n", fileName);
        exit(0x0);
    }
    else{
        printf("Opened\n\n");
    }

    size = getFileSize();
    printf("Reading file, size: %ld b\n\n", size);
}

void closeInputFile(){
    fclose(inputFile);
}

size_t getFileSize(){
    size_t size;
    fseek(inputFile, 0, SEEK_END);
    size = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);
    return size;
}

int isDecDigit(char c){
    return ('0' <= c && c <= '9');
}

int isDigit(char c){
    return ('0' <= c && c <= '9') || ('A' <= c && c <= 'F');
}

int isRealCharacter(char c){
    return 32 < c;
}

char nextChar(){
    char c = fgetc(inputFile);

    if(c == '\n'){
        bufferColumn = 1;
        bufferRow++;
    }
    else if(c == '\r'){
        return nextChar();
    }
    else if(c != EOF){
        bufferColumn++;
    }
    else{
        if(!endOfFile)
            printf("Got end of file!\n");
        endOfFile = ERROR;
    }
    return c;
}

char checkNextChar(){
    char c = nextChar();
    ungetc(c, inputFile);
    bufferColumn--;
    return c;
}

NumPointer readNumber(int system){
    char c;
    int i, temp, size;
    NumPointer a = createNumber(-1);

    a->system = system;

    while(!isRealCharacter(c = nextChar()));

    do{
        if(num(c) < system){
            pushVector(a->number, num(c));
        }
        else{
            handleInputError("Number contain characters that are not allowed in numeric system", ERROR);
            return a;
        }
    } while(isRealCharacter(c = nextChar()));

    size = a->number->size;
    for(i = 0; i < (size / 2); i++){
        temp = a->number->value[i];
        a->number->value[i] = a->number->value[size - i - 1];
        a->number->value[size - i - 1] = temp;
    }

    cleanZeros(a); 
    return a;
}

NumPointer readNextArgument(int system){
    int n = goToNonWhiteCharacter();

    if(n >= 3 || endOfFile){
        return createNumber(-1);
    }
    else{
        return readNumber(system);
    }
}

int goToNonWhiteCharacter(){
    char c;
    int i = 0;
    while(!endOfFile && (c = checkNextChar()) <= 32){
        if(c == '\n'){
            i++;
        }
        nextChar();
    }
    return i;
}

struct InputResponse handleSegment(){
    char c;
    
    goToNonWhiteCharacter();
    
    c = nextChar();
    inputError = SUCCESS;

    if(isDecDigit(c)){
        return getSystemChangeSegment(c);
    }
    else{
        return getCalculationSegment(c);
    }
}

struct InputResponse getCalculationSegment(char first){
    struct InputResponse response;
    NumPointer in;
    int systemIn;

    if(nextChar() != ' '){
        return handleInputError("(a) Unexpected character, expected ' '", ERROR);
    }

    if(!isDecDigit(checkNextChar())){
        return handleInputError("(b) Unexpected character, expected base of numbers", ERROR);
    }

    in = readNumber(10);
    systemIn = readIntFromNumber(in);
    deleteNumber(&in);

    response.type = Calculation;
    response.systemIn = systemIn;
    response.operation = first;
    return response;
}

struct InputResponse getSystemChangeSegment(char first){
    struct InputResponse response;
    NumPointer out = NULL;

    int systemIn = first - '0';
    int systemOut;
    char c = nextChar();

    if(isDecDigit(c)){
        systemIn = (c - '0') + systemIn * 10;
        if(nextChar() != ' '){
            return handleInputError("(c) Unexpected character, expected ' '", ERROR);
        }
    }
    else if(c != ' '){
            return handleInputError("(d) Unexpected character, expected ' '", ERROR);
        return response;
    }

    out = readNumber(10);
    systemOut = readIntFromNumber(out);
    deleteNumber(&out);

    response.type = SystemChange;
    response.systemIn = systemIn;
    response.systemOut = systemOut;
    return response;
}

struct InputResponse handleInputError(const char* message, int error){
    struct InputResponse nullResponse;
    inputError = error;

    if(error == SUCCESS){
        printf("%s\n", message);
        return nullResponse;
    }
    else if(error == WARNING){
        printf("----------------------------------------\n");
        printf("Warning occurred while processing input:\n");
        printf("\t%s\n", message);
        printf("\tIn line %d\n", bufferRow);
        printf("\tIn column %d\n", bufferColumn);
        printf("----------------------------------------\n\n");
        return nullResponse;
    } else {
        printf("----------------------------------------\n");
        printf("Error occurred while processing input:\n");
        printf("\t%s\n", message);
        printf("\tIn line %d\n", bufferRow);
        printf("\tIn column %d\n", bufferColumn);
        printf("Waiting for triple enter...\n");
        printf("----------------------------------------\n\n");

        skipCurrentSegment();
    }

    return nullResponse;
}

void skipCurrentSegment(){
    int i = 0;
    char c = 0;

    while(c = checkNextChar()){
        /*printf("Checked i:%d, char: %d\n", i, c);*/
        if(c > 32){
            i = 0;
        }
        if(c == '\n'){
            i++;
        }
        if(i == 4){
            return;
        }
        if(endOfFile == ERROR){
            return;
        }
        nextChar();
    }
}