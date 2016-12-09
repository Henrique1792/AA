#ifndef FILES_H_
#define FILES_H_
#include "utils.h"

FILE *openFile(char *fileName);
void closeFile(FILE *tgt);
char *readFileLine(FILE *tgt);
#endif
