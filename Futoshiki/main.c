#include "table.h"



int main(int argc, char *argv[]){
  if(argc>1){
    if(!strcmp(argv[1],"MVR"))  printf("MVR SET UP\n");
  }
  
  GAME *jogo=create_game(4,2);
  free_game(&jogo);
   
  return 0;
}
