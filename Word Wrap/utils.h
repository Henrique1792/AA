#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <limits.h>
#include "files.h"
#define maxLineSize 81
#define maxWordNumber 1000
#define SQR(x) x*x



int *getWordSizes(FILE *tgt);
int getParameters(FILE *tgt);
#endif
