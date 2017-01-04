#include "map.h"



int main(){
  MAP *teste;
  mapStartUp(&teste,openFile("teste.dat"));
  printMap(teste);
  freeMap(&teste);
  
  return 0;
}
