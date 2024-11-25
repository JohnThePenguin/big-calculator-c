/*
    File: error.h
    Description: 
        File contains definition of error functions
        used for throwing exceptions and exiting program
*/

#ifndef ERROR_H
#define ERROR_H

#define SUCCESS 0
#define ERROR   1
#define WARNING 2

/* Flag if EOF character appeared */
extern int endOfFile;

/*
    Function throws error message and exits program
    @param s - message to be printed
    @return void
*/
void error(const char* s);

/*
    Function exits program with given exit code
    @param code - exit code
    @return void
*/
void exitProcess(int code);

#endif