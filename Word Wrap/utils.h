#ifndef UTILS_H_
#define UTILS_H_
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define maxLineSize 81
#define maxWordNumber 1000






FILE *open_file(char *fileName);
void close_file(FILE *tgt);

int get_parameters(FILE *tgt);



#endif
