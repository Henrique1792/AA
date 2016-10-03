#include "table.h"




INEQUATION *create_inq(){
  INEQUATION *rt=(INEQUATION *)malloc(sizeof(INEQUATION));
  rt==NULL ? NULL : rt;
}

int set_inq_values(INEQUATION *tgt, int x1, int x2, int y1, int y2, int size){
  if((x1>=size ||x1<0)||
    (x2>=size ||x2<0)||
    (y1>=size ||y1<0)||
    (y2>=size ||y2<0)|| tgt==NULL) return FAIL;

  tgt->x1=x1;  
  tgt->x2=x2;  
  tgt->y1=y1;  
  tgt->y2=x2; 
  return SUCCESS;
}

void free_inq(INEQUATION **tgt){
  if(tgt==NULL || *tgt==NULL) return;
  free(*tgt);
}




GAME *create_game(int size,int inequations){
  if(size <0 || size <4||size>9 || inequations <=0) return NULL;
  GAME *rt=(GAME *)malloc(sizeof(GAME));
  int i,j,x1,x2,y1,y2;
  
  rt->table=(int **)malloc(size*sizeof(int *));
  for (i=0;i<size;i++) rt->table[i]=(int *)malloc(size*sizeof(int));
 
  for(i=0;i<size;i++){
    for(j=0;j<size;j++) 
      rt->table[i][j]=DEFAULT;
  }
  
  
  
  rt->inequations=(INEQUATION *)malloc(inequations*sizeof(INEQUATION));
  rt->nInequations=inequations; 
  for(i=0;i<inequations;i++){
   scanf("%d, %d, %d, %d",&x1, &x2, &y1, &y2);
   j=set_inq_values(&(rt->inequations[i]),x1,x2,y1,y2,size);
  }
  return rt;  
}
void free_game(GAME **tgt);
