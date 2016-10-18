#ifndef RULES_H_
#define RULES_H_

#include "table.h"


/*
 *check_line
 *Description: Check line  of tgt game
 *ARGS: line
 *Returns SUCCESS if line obey futoshiki's rules; FALSE instead
*/
int check_line(int line);

/*
 *check_column
 *Description: Check column of current game
 *ARGS: column
 *Returns SUCCESS if column obey futoshiki's rules; FALSE instead
*/
int check_column(int column);

/*
 *check_inequations
 *Description: Check inequations of current game
 *ARGS: No args
 *Returns SUCCESS if inequations are ok; FALSE instead
*/
int check_inequations(int x, int y);
#endif
