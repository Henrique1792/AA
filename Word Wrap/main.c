#include "ww.h"

extern int lineSize, nWords,*wordSequence,jump;
int main(){
  FILE *rt = openFile("teste.dat");
  int *teste;
  getParameters(rt);
  teste=getWordSizes(rt);
  jump=0;
  solveWordWrap(teste);
  
  closeFile(rt);
  
  rt=openFile("teste.dat");
  getParameters(rt);
  output(rt);
  
  
  
  
  
  free(wordSequence);
  free(teste);
  closeFile(rt);
  return 0;
}
