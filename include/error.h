#ifndef ERROR_H
#define ERROR_H

#define SUCCESS 0
#define ERROR   1
#define WARNING 2

extern int endOfFile;

void error(const char* s);

void exitProcess(int code);

#endif