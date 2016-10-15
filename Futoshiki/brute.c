#include "brute.h"



void brute_force_iter(int **board,int *line, int *column){
   
  
}

  
  
void brute_force(GAME *tgt){
  if(tgt==NULL) return;
  int i,j;
  int **board;
  i=j=0;
   
  board=(int **)malloc(tgt->size*sizeof(int *));
  for(i=0;i<tgt->size;i++) board[i]=(int *)malloc(tgt->size*sizeof(int));


  brute_force_iter(board, &i, &j); 
  for(i=0;i<tgt->size;i++) free(board[i]);
  free(board);
}


void Look_Ahead(GAME *tgt);
void MVR(GAME *tgt);
