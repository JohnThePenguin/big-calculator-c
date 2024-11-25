#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

/* Descriptions and comments are in include/output.h */

/* Pointer to file, available outside */
FILE *outputFile;

void openOutputFile(int argc, char *argv[]){
    char* outputFileName;
    if(argc == 3){
        /* If file name passed, use passed */
        outputFileName = argv[2];
    }
    else { 
        /* Convert passed input file name to out_[name]*/
        char* inputFileName = argv[1];
        char* outString = "out_";
        outputFileName = malloc(strlen(inputFileName) + 5);

        strcpy(outputFileName, outString); /* Copy out_ */
        strcat(outputFileName, inputFileName); /* Merge out_ with input name*/
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

void outputString(char cstr[]){
    fprintf(outputFile, "%s", cstr);
}

void closeOutputFile(){
    fclose(outputFile);
}