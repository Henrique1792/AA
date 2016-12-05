#include "utils.h"

extern int line_size, nWords;

int main(){
  FILE *teste=open_file("teste.dat");
  int i=get_parameters(teste);
  close_file(teste);
  return 0;
}
