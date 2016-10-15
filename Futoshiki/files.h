#ifndef FILES_H
#define FILES_H

#include "table.h"

/*
 *openFile
 *Description: opens a certain file.
 *ARGS: filename.
 *Returns the opened file or NULL.
*/
FILE *openFile(char *filename);

/*
 *readLine
 *Description: reads a line in a certain file.
 *ARGS: stream file.
 *Returns a readed line or NULL if reached EOF/error ocurred.
*/
char *readLine(FILE *stream);

/*
 *readNumberOfCases
 *Description: reads the number of cases.
 *ARGS: stream file.
 *Returns the number of cases or -1 if error.
*/
int readNumberOfCases(FILE *stream);

/*
 *readTableConfig
 *Description: reads the next table configuration.
 *ARGS: stream file.
 *Returns the size of the table [0] and number of inequations [1] or NULL if error.
*/
int *readTableConfig(FILE *stream);

/*
 *readGameTable
 *Description: reads the game table.
 *ARGS: table size, number of inequations and stream file.
 *Returns the next game read or NULL if error.
*/
GAME *readGameTable(int size, int nInequations, FILE *stream);

/*
 *closeFile
 *Description: closes a certain file.
 *ARGS: file.
 *No return.
*/
void closeFile(FILE *file);

#endif
