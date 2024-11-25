/*
    File: output.h
    Description:
        File contains declarations of functions 
        and structures used for writing output to file.
*/

#ifndef VECTOR_H
#define VECTOR_H

/* Pointer for output file, available from outside */
extern FILE *outputFile;

/*
    Function opens output file for writing based on program arguments
    If output file is not given, it creates new file with name out_[inputFileName]
    Does not check for inputFileName, input.h should handle it
    @param argc - number of arguments
    @param argv - array of arguments
    @return void
*/
void openOutputFile(int argc, char *argv[]);

/*
    Function writes integer to output file
    @param a - integer to be written
    @param end - character to be written after integer
    @return void
*/
void outputInt(int a, char end);

/*
    Function writes character to output file
    @param c - character to be written
    @return void
*/
void outputChar(char c);

/*
    Function closes output file
    @return void
*/
void closeOutputFile();

#endif