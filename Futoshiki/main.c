#include "table.h"



int main(int argc, char *argv[]){
  if(argc>1){
    if(!strcmp(argv[1],"MVR"))  printf("MVR SET UP\n");
  }
  else printf("BRUTE MODE\n");
  GAME *teste=create_game(4,2);
  free_game(&teste);
  return 0;
}
