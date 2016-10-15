#ifndef RULES_H_
#define RULES_H_

#include "table.h"
#include "quick.h"


/*
 *check_lines
 *Description: Check line  of tgt game
 *ARGS:game target, line
 *Returns SUCCESS if line obey futoshiki's rules; FALSE instead
*/
int check_line(GAME *tgt, int line);

/*
 *check_columns
 *Description: Check coolumn  of tgt game
 *ARGS:game target, column
 *Returns SUCCESS if column obey futoshiki's rules; FALSE instead
*/
int check_column(GAME *tgt, int column);

#endif
