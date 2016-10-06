#include "rules.h"




/*Não gostei dessa opção...
 * não sei como serão as chamadas da função
 * recursiva acima, pode gerar muito 
 * tempo de execução.
*/
int check_lines(GAME *tgt){
  if(tgt==NULL)  return FAIL;
  int i,j,k,*chk;
  

  for(i=0;i<tgt->size;i++){
    for(j=0;j<tgt->size;j++){
      if(tgt->table[i][j]==DEFAULT) break;
    }
    memcpy(chk,tgt->table[i],sizeof(tgt->table[i]));
    quicksort(chk,0,(tgt->size)-1);
   
    for(k=0;k<tgt->size;k++){
      if(tgt->possible_values[k]!=chk[k]){
        free(chk);
        return FAIL;
      }
      free(chk);
    }
  }
  return SUCCESS;
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
