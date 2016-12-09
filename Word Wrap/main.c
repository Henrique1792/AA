#include "ww.h"

extern int lineSize, nWords;
int main(){
  FILE *rt = openFile("teste.dat");
  int *teste;
  getParameters(rt);
  teste=getWordSizes(rt);
  solveWordWrap(teste);
  free(teste);
  closeFile(rt);
  return 0;
}
