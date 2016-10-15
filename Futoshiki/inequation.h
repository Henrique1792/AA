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

/*
 *create_inq
 *Description: Creates a new inequation struct.
 *ARGS:None
 *Returns inequation if success or NULL.
*/
INEQUATION *create_inq();

/*
 *copy_inq
 *Description: copies a certain inequation structure.
 *ARGS:origin structure, origin size;
 *Returns the copied inequation if success or NULL.
*/
INEQUATION *copy_inq(INEQUATION *origin, int size);

/*
 *set_inq_values
 *Description: Set an inequation values.
 *ARGS:Target inequation, coordinates of point 1, coordinates of point 2, table size.
 *Returns Success if conditions, else return Fail.
*/
int set_inq_values(INEQUATION *tgt,int x1, int x2, int y1, int y2, int size);

/*
 *free_inq
 *Description: Free Inequation Structure tgt
 *ARGS:Inequation Target.
 *No Return.
*/
void free_inq(INEQUATION *tgt);

/*
 *print_inq
 *Description: Print an inequation.
 *ARGS:Target inequation
 *No Return
*/
void print_inq(INEQUATION tgt);




#endif
