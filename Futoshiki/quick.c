#include "quick.h"











void swap(int *vector, int i, int j) {
  int aux = vector[i];
  vector[i] = vector[j];
  vector[j] = aux;
}

int partition(int *vector, int left, int right) {
  int j, i = left;
  
  for (j = i+1; j <= right; j++) {  // n-1
      if (vector[j] < vector[left]) {  // c
          i++;
          swap(vector, i, j);
        }
  }
  swap(vector, left, i);

  return i;
}

void quicksort(int *vector, int left, int right) {
  int pivo;

  if (left < right) {
      pivo = partition(vector, left, right);
      quicksort(vector, left, pivo-1);
      quicksort(vector, pivo+1, right);
    }
}
