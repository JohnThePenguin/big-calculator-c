#ifndef VECTOR_H
#define VECTOR_H

extern FILE *outputFile;

void openOutputFile(int argc, char *argv[]);

void outputInt(int a, char end);

void outputChar(char c);

void closeOutputFile();

#endif