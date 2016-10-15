#include "brute.h"


GAME *global_game;
int brute_force_iter(int **board,int line, int column, int size){
    if(line==size) return SUCCESS;
    if(column == size){
      column=0;
      line++;
    }
    int i;

   for(i=0;i<size;i++){
    board[line][column]=i;
    if((check_line(global_game,line)&&check_column(global_game,column)&& check_inequations(global_game)) 
      && brute_force_iter(board,line,column++,size)) return SUCCESS;
   }
   
   board[line][column]=0;
   column--;
   if(column<0){
    column=size-1;
    line--;
   }
   return FAIL;
}

  
  
void brute_force(GAME *tgt){
  if(tgt==NULL) return;
  int i,j;
  int **board;
   
  board=(int **)malloc(tgt->size*sizeof(int *));
  for(i=0;i<tgt->size;i++) board[i]=(int *)malloc(tgt->size*sizeof(int));
  
  for(i=0;i<tgt->size;i++){
    for(j=0;j<tgt->size;j++) board[i][j]=tgt->table[i][j];
  }

  i=j=0;



  brute_force_iter(board, i, j,tgt->size); 
  for(i=0;i<tgt->size;i++) free(board[i]);
  free(board);
}


void Look_Ahead(GAME *tgt);
void MVR(GAME *tgt);
