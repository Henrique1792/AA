#ifndef QUICK_H_
#define QUICK_H_

#include <stdlib.h>
#include <stdio.h>



/*
*swap
  *Description: Swap values i and j in vector.  
  *Args: vector, i, j
  *No Return
*/
void swap(int *vector, int i, int j);

/*
*partition
  *Description:Set partition for quicksorting.  
  *Args: vector, left, right,
  *Returns central point of partition
*/
int partition(int *vector, int left, int right);

/*
*quicksort
  *Description: Applies quicksort on vector.  
  *Args: vector, left, right
  *No Return
*/
void quicksort(int *vector, int left, int right); 

#endif
