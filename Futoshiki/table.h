#ifndef TABLE_H_
#define TABLE_H_

#include "inequation.h"


typedef struct GAME{
  int **table;
  int size;
  int nInequations;
  int *possible_values;
  INEQUATION *inequations;
}GAME;

GAME *create_game(int size,int inequations);
void print_table(GAME *tgt);
void free_game(GAME **tgt);

#endif
