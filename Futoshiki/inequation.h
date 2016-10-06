#ifndef INEQUATION_H_
#define INEQUATION_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0
#define DEFAULT 0


typedef struct INEQUATION{
  int x1, x2; //point A
  int y1, y2; //point B
}INEQUATION;

INEQUATION *create_inq();
int set_inq_values(INEQUATION *tgt,int x1, int x2, int y1, int y2, int size);

void free_inq(INEQUATION *tgt);

void print_inq(INEQUATION tgt);




#endif
