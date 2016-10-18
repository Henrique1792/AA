#ifndef BRUTE_H_
#define BRUTE_H_

#include "rules.h"
#include "table.h"

/*
 *brute_force
 *Description: Applies bruteforce technique to solve Futoshiki game.
 *ARGS:target game.
 *No Return.
*/
void brute_force();

/*
 *Look_Ahead
 *Description: Applies bruteforce technique
 *             with Look Ahead Heuristics to solve Futoshiki game.
 *ARGS:No Args.
 *No Return.
 */
void look_ahead();

/*
 *MVR
 *Description: Gets the next most restrict value in the table
               and updates the current line & column to its values.
 *ARGS: Current line, current column.
 *No Return.
*/
void MVR(int *line, int *column);

#endif
