#include "brute.h"

#define MAX_ITER 1000000

/* Referencia para as variaveis globais em testmain.c */
extern GAME *mask;
extern GAME *curGame;
int **auxboard;
/* Contador de iteracoes */
int iter_count = 0;

int brute_force_iter(int line, int column){
    if(column >= curGame->size){
        column = 0;
        line = line + 1;
    }

    if(line == curGame->size) return SUCCESS;

    if(mask->table[line][column] != 0) return brute_force_iter(line, column + 1);

    int i = 1;
    for(i = 1; i <= curGame->size; i++){
        curGame->table[line][column] = i;

        if((check_line(line) && check_column(column)
            && check_inequations(line, column)) && brute_force_iter(line, column + 1))
            return SUCCESS;
    }

    curGame->table[line][column] = mask->table[line][column];

    return FAIL;
}

void brute_force(){
    if(curGame == NULL) return;
    brute_force_iter(0, 0);
}



int LookAhead_iter(int line, int column){
  int i;
  //Reach end of line.
  if(column>=curGame->size){
    column=0;
    line++;
  }
  
  //Reach end of Game
  if(line == curGame->size) return SUCCESS;
 
  //Find an value set by user.
  if(mask->table[line][column]!=0){
    return LookAhead_iter(line, column+1);
  }

  //All Possibilities were used.
  if(auxboard[line][column]==0)  return FAIL;
 
  //Check Line, Column, possible Inequations
  for(i=1;i<=curGame->size;i++){
    curGame->table[line][column] = i;
    if((check_line(line) && check_column(column) && check_inequations(line, column)) 
      && LookAhead_iter(line, column+1)){
      auxboard[line][column]--;
      return SUCCESS;
    }
    
  }
  
  //Set Current value to it's mask. 
  curGame->table[line][column]=mask->table[line][column];
  return FAIL;
}

void Look_Ahead(){
  if(curGame==NULL) return;
  int i,j;
  auxboard=(int **)malloc(curGame->size*sizeof(int *));

  for(i=0;i<curGame->size;i++) auxboard[i]=(int *)malloc(curGame->size*sizeof(int));
  for(i=0;i<curGame->size;i++){
    for(j=0;j<curGame->size;j++){
      auxboard[i][j]=curGame->size;
    }
  }
  LookAhead_iter(0,0);
  for(i=0;i<curGame->size;i++) free(auxboard[i]);
  free(auxboard);
}
  


/*int mvr_iter(int line, int column){}*/
void MVR(GAME *tgt){
  if(curGame==NULL) return;
  /*Analisar as restrições aqui*/
//  mvr_iter(0,0);
}
