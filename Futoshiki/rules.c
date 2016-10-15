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


int check_line(GAME *tgt, int line){
  if(tgt==NULL || line<0 || line >=tgt->size)  return FAIL;
  int j, result=FAIL,*chk=NULL;


    for(j=0;j<tgt->size;j++){
      if(tgt->table[line][j]==DEFAULT) return result;
    }      
    
    memcpy(chk,tgt->table[line],sizeof(tgt->size));
    quicksort(chk,0,(tgt->size)-1);
    result=compare_vectors(chk,tgt->possible_values,tgt->size);
    free(chk);
    
  return result;
}

int check_column(GAME *tgt, int column){
  if(tgt==NULL || column<0 || column>=tgt->size)  return FAIL;
  int j, result=FAIL,*chk=NULL;

  
    for(j=0;j<tgt->size;j++){    
      if(tgt->table[j][column]==DEFAULT) return result;
    }

    chk=(int *)malloc(tgt->size*sizeof(int));
      for(j=0;j<tgt->size;j++) chk[j]=tgt->table[j][column];
    
    quicksort(chk,0,(tgt->size)-1);
    result=compare_vectors(chk,tgt->possible_values,tgt->size);
    free(chk);
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
