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

/*
 *create_game
 *Description: Creates a new game struct.
 *ARGS:size, number of inequations.
 *Returns game if success or NULL.
*/
GAME *create_game(int size, int inequations);

/*
 *copy_game
 *Description: copies a certain game structure.
 *ARGS:origin game
 *Returns GAME copy or NULL if error.
*/
GAME *copy_game(GAME *origin);

/*
 *print_table_header
 *Description: print header gameplay.
 *ARGS:target game
 *No return.
*/
void print_table_header(GAME *tgt);

/*
 *print_table_board
 *Description: Prints tgt game table.
 *ARGS:target game
 *No Return.
*/
void print_table_board(GAME *tgt);

/*
 *print_table_inqs
 *Description: Print inequations of game
 *ARGS:target game
 *No Return
*/
void print_table_inqs(GAME *tgt);

/*
 *print_table
 *Description: Print whole game structure.
 *ARGS:target game
 *No Return
*/
void print_table(GAME *tgt);

/*
 *free_game
 *Description: Free game structure
 *ARGS:target game
 *No Return
*/
void free_game(GAME **tgt);

#endif
