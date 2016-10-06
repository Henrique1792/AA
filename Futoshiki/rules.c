#include "rules.h"



int compare_vectors(int *v1, int *v2, int size){
  int k;
  

  for(k=0;k<size;k++){
    if(v1[k]!=v2[k]){
      return FAIL;
    }
  }
  return SUCCESS; 
}




int check_lines(GAME *tgt){
  if(tgt==NULL)  return FAIL;
  int i, j, result,*chk;


  for(i=0;i<tgt->size;i++){
    for(j=0;j<tgt->size;j++){
      if(tgt->table[i][j]==DEFAULT){
        result=FAIL; 
        break;
      }
    }      
    
    if(result==FAIL) break;
    memcpy(chk,tgt->table[i],sizeof(tgt->table[i]));
    quicksort(chk,0,(tgt->size)-1);
    result=compare_vectors(chk,tgt->possible_values,tgt->size);
    free(chk);
    if(result==FAIL)  break;
    
  }
  return SUCCESS;
}

int check_columns(GAME *tgt){
  if(tgt==NULL)  return FAIL;
  int i, j, result,*chk;

  
  for(i=0;i<tgt->size;i++){
    for(j=0;j<tgt->size;j++){    
      if(tgt->table[j][i]==DEFAULT){
        result=FAIL;
        break;
      }
    }

    if(result==FAIL) break;
    chk=(int *)malloc(tgt->size*sizeof(int));
    for(j=0;j<tgt->size;j++) chk[j]=tgt->table[j][i];
    
    quicksort(chk,0,(tgt->size)-1);
    result=compare_vectors(chk,tgt->possible_values,tgt->size);
    free(chk);
    if(result==FAIL) break;
  }
  return result;
  
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
