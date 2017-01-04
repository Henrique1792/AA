#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define BLANK -1
#define HEADER -2


/*
 * file handling functions.
*/
FILE *openFile(char *tgt);
void closeFile(FILE *tgt);
char *readLine(FILE *tgt);
int readInt(FILE *tgt);



#endif
