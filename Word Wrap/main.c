#include "ww.h"

extern int lineSize, nWords;

int main(){
  FILE *rt = openFile("teste.dat");
  getParameters(rt);
  int *teste=getWordSizes(rt);
  int *solution,i; 
  solution=solveWordWrap(teste);

  for(i=0;i<nWords;i++) printf("%d ",solution[i]);
  printf("\n");
  free(teste);
  free(solution);
  closeFile(rt);
  return 0;
}
