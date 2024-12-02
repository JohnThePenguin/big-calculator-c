#include "input.h"
#include "output.h"
#include "error.h"
#include "numbers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Descriptions and comments are in include/input.h */

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

/* Is "visible" (non-white) character */
int isRealCharacter(char c){
    return 32 < c;
}

/* Function for reading next char from file */
/* Tracks position of buffer, ignores \r */
/* Marks flag if read end of file */
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

/* Function for only checking, not moving forward */
char checkNextChar(){
    char c = nextChar();
    ungetc(c, inputFile);
    if(c == '\n'){ /* possible mistake - ignoring */
        bufferRow--;
    }
    else{
        bufferColumn--;
    }
    return c;
}

int isValidOperation(char operation){
    return (
        operation == '+' ||
        operation == '*' ||
        operation == '/' ||
        operation == '%' ||
        operation == '^'
    );
}

NumPointer readNumber(int system){
    char c;
    int i, temp, size;
    NumPointer a = createNumber(-1);

    a->system = system;

    /* Skip all white characters */
    while(!isRealCharacter(c = nextChar()));

    do{
        if(num(c) < system){
            /* When character is fine, push it to result */
            pushVector(a->number, num(c));
        }
        else{
            handleInputError("Number contain characters that are not allowed in numeric system", ERROR);
            return a;
        }
    } while(isRealCharacter(c = nextChar()));
    /* As long as character is "non-white" */

    /* Reverse it to big-endian */
    size = a->number->size;
    for(i = 0; i < (size / 2); i++){
        temp = a->number->value[i];
        a->number->value[i] = a->number->value[size - i - 1];
        a->number->value[size - i - 1] = temp;
    }

    cleanZeros(a); 
    return a;
}

/* Same, but counts if number is part of existing question segment */
NumPointer readNextArgument(int system){
    /* n - number of \n before non-white character */
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

    /* As long as character is non-white, count \n */
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

    /* Skip to start of segment */ 
    goToNonWhiteCharacter();
    
    c = nextChar();
    inputError = SUCCESS;

    /* Check is character digit or operation */
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
    char operationMessage[] = "Wrong operation:  ";

    /* Format: [first] [digits...*/

    /* Check is operation available */
    if(!isValidOperation(first)){
        operationMessage[17] = first;
        return handleInputError(operationMessage, 1);
    }

    if(nextChar() != ' '){
        return handleInputError("(a) Unexpected character, expected ' '", ERROR);
    }

    if(!isDecDigit(checkNextChar())){
        return handleInputError("(b) Unexpected character, expected base of numbers", ERROR);
    }

    in = readNumber(10);
    systemIn = readIntFromNumber(in);

    if(2 > systemIn || systemIn > 16){
        return handleInputError("System of numbers on input should be between 2 and 16", ERROR);
    }

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

    /* Format [first][c?] [digits...] */
    /* If c is digit than system > 10 */
    /* else c must be space */

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

    
    if(2 > systemIn || systemIn > 16 || 2 > systemOut || systemOut > 16){
        return handleInputError("System of numbers on input should be between 2 and 16", ERROR);
    }

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
        printf("\tNearby place:\n");
        printf("\tLine: %d\n", bufferRow);
        printf("\tColumn: %d\n", bufferColumn - 1);
        printf("----------------------------------------\n\n");
        return nullResponse;
    } else {
        printf("----------------------------------------\n");
        printf("Error occurred while processing input:\n");
        printf("\t%s\n", message);
        printf("\tNearby place:\n");
        printf("\t\tLine: %d\n", bufferRow);
        printf("\t\tColumn: %d\n", bufferColumn - 1);
        printf("Waiting for triple enter...\n");
        printf("----------------------------------------\n\n");

        skipCurrentSegment();
    }

    return nullResponse;
}

void skipCurrentSegment(){
    int i = 0;
    char c = 0;

    /* Wait for 4 \n without anything visible between it */
    while(c = checkNextChar()){
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