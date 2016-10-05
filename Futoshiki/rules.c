#include "rules.h"



int check_lines(GAME *tgt){
  if(tgt==NULL)  return FAIL;
  int i,j,*chk;
  
  chk=(int *)malloc((tgt->size)*sizeof(int));
  for(i=0;i<tgt->size;i++){
    for(j=0;j<tgt->size;j++){
      if(tgt->table[i][j]==DEFAULT) break;
      
      
    }
  }
  free(chk);
}

int check_columns(GAME *tgt){
  if(tgt==NULL) return FAIL;
  
  
}

int check_inequations(GAME *tgt){
  if(tgt==NULL) return FAIL;
  int i;
 
  for(i=0;i<tgt->nInequations;i++){
    if(tgt->table[tgt->inequations[i].x1][tgt->inequations[i].x2] >
        tgt->table[tgt->inequations[i].y1][tgt->inequations[i].y2]){
      return FAIL;  
    }
  }
  return SUCCESS;
}
