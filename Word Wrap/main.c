#include "ww.h"

extern int lineSize, nWords, *wordSequence;

int main(){
  FILE *rt = openFile("teste.dat");
  getParameters(rt);
  int *teste=getWordSizes(rt);
  wordSequence=(int *)malloc(nWords*sizeof(int));
  solveWordWrap(teste);
  
  
  
  
  free(teste);
  closeFile(rt);
  free(wordSequence);
  return 0;
}
