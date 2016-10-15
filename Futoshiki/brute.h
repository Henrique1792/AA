#ifndef BRUTE_H_
#define BRUTE_H_

#include "rules.h"




/*
 *brute_force
 *Description: Applies bruteforce technique to solve Futoshiki game.
 *ARGS:target game.
 *No Return.
*/
void brute_force(GAME *tgt);

/*
 *Look_Ahead
 *Description: Applies bruteforce technique 
 *             with Look Ahead Heuristics to solve Futoshiki game
 *ARGS:target game.
 *No Return.
 */
void Look_Ahead(GAME *tgt);

/*
 *MVR
 *Description: Applies bruteforce technique
 *             with MVR Heuristics to solve Futoshiki game.
 *ARGS: target game.
 *No Return.
*/
void MVR(GAME *tgt);



#endif
