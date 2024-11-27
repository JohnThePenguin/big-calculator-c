/*
    File: input.h
    Description:
        File contains declarations of functions 
        and structures used for reading input from file.
*/

#ifndef INPUT_H
#define INPUT_H

#include "numbers_core.h"
#include "error.h"

/* Enum for operation type */
enum OperationType {
    Calculation = 0,
    SystemChange = 1
};

/* 
    Structure for input response
    type - type of operation
    systemIn - system of input numbers
    systemOut - system of output numbers
    operation - char of operation to be performed
*/
struct InputResponse{
    enum OperationType type;
    int systemIn;
    int systemOut;
    char operation;
};

/* Flag if error in input syntax appeared */
extern int inputError;

/* 
    Function opens input file for reading based on program arguments
    Checks if file name is passed as argument
    @param argc - number of arguments
    @param argv - array of arguments
    @return void
*/
void openInputFile(int argc, char* argv[]);

/* 
    Function closes input file
    @return void
*/
void closeInputFile();

/* 
    Function returns size of input file
    @return size_t - size of file
*/
size_t getFileSize();

/* 
    Function goes to first non white character and counts \n characters
    @return int - number of \n characters
*/
int goToNonWhiteCharacter();

/* 
    Function checks if given character is valid operation (+, *, /, %, ^)
    @param operation - character to be checked
    @return int - 1 if valid, 0 otherwise
*/
int isValidOperation(char operation);

/* 
    Function reads first digits and creates new number from them
    It skips all white characters before
    It checks if number is in given system
    @param system - system of number
    @return pointer to created, read number
*/
NumPointer readNumber(int system);

/* 
    Function if there is no more than 3 \n, 
    calls returns readNumber result, 
    otherwise returns -1 as value of number structure
    @param system - system of number
    @return pointer to created, read number
*/
NumPointer readNextArgument(int system);

/*
    Function handles first line of definition of operation
    It handles syntax errors and returns response
    @return structure with response
*/
struct InputResponse handleSegment();

/*
    Function skips current segment of input
    Made for handling errors
    @return void
*/
void skipCurrentSegment();

/*
    Function returns response for calculation segment
    and checks for syntax errors
    @param first - first character of segment
    @return structure with response
*/
struct InputResponse getCalculationSegment(char first);

/*
    Function returns response for system change segment
    and checks for syntax errors
    @param first - first character of segment
    @return structure with response
*/
struct InputResponse getSystemChangeSegment(char first);

/*
    Function handles input error
    It prints message and returns null response
    If error is fatal, it skips current segment
    @param message - message to be printed
    @param errorCode - error code from error.h
    @return structure with response
*/
struct InputResponse handleInputError(const char* message, int errorCode);

#endif