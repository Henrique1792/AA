#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define maxLineSize 81
#define maxWordNumber 1000
#define SQR(x) x*x



FILE *openFile(char *fileName);
void closeFile(FILE *tgt);
int *getWordSizes(FILE *tgt);
int getParameters(FILE *tgt);
int printSolution (int p[], int n);


#endif
