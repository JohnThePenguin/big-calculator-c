#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"


FILE *outputFile;

void openOutputFile(int argc, char *argv[]){
    char* outputFileName;
    if(argc == 3){
        outputFileName = argv[2];
    }
    else { 
        char* inputFileName = argv[1];
        char* outString = "out_";
        outputFileName = malloc(strlen(inputFileName) + 5);

        strcpy(outputFileName, outString);
        strcat(outputFileName, inputFileName);
    }

    printf("Trying to open file for output: %s...\n", outputFileName);
    outputFile = fopen(outputFileName, "w");

    if(outputFile == NULL){
        error("Could not open / create output file");
    }
    else{
        printf("Opened\n\n");
    }
}

void outputInt(int a, char end){
    fprintf(outputFile, "%d%c", a, end);
}

void outputChar(char c){
    fprintf(outputFile, "%c", c);
}

void closeOutputFile(){
    fclose(outputFile);
}