#ifndef TABLE_H_
#define TABLE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SUCCESS 1
#define FAIL 0
#define DEFAULT -1


typedef struct INEQUATION{
  int x1, x2; //point A
  int y1, y2; //point B
}INEQUATION;

INEQUATION *create_inq();
int set_inq_values(INEQUATION *tgt,int x1, int x2, int y1, int y2, int size);
void free_inq(INEQUATION **tgt);

typedef struct GAME{
  int **table;
  int size;
  int nInequations;
  int *possible_values;
  INEQUATION *inequations;
}GAME;

GAME *create_game(int size,int inequations);
void free_game(GAME **tgt);

#endif
