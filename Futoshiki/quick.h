#ifndef QUICK_H_
#define QUICK_H_

#include <stdlib.h>
#include <stdio.h>


void swap(int *vector, int i, int j); 
int partition(int *vector, int left, int right);
void quicksort(int *vector, int left, int right);


#endif
