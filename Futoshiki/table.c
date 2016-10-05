#include "table.h"
#include "inequation.h"

GAME *create_game(int size,int inequations){
  if(size <0 || size <4||size>9 || inequations <=0) return NULL;
  GAME *rt=(GAME *)malloc(sizeof(GAME));
  int i,j,a1,a2,b1,b2;

  rt->table=(int **)malloc(size*sizeof(int *));
  for (i=0;i<size;i++) rt->table[i]=(int *)malloc(size*sizeof(int));

  for(i=0;i<size;i++){
    for(j=0;j<size;j++)
      rt->table[i][j]=DEFAULT;
  }

  rt->possible_values=(int *)malloc(size*sizeof(int));
  for(i=0;i<size;i++) rt->possible_values[i]=i+1;


  rt->inequations=(INEQUATION *)malloc(inequations*sizeof(INEQUATION));
<<<<<<< HEAD
  rt->nInequations=inequations;
=======
  rt->nInequations=inequations; 
  
  for(i=0;i<inequations;i++){
    scanf("%d %d %d %d",&a1, &a2, &b1, &b2);
    j=set_inq_values(&(rt->inequations[i]),a1,a2,b1,b2,size);
  }
>>>>>>> working

  rt->size=size;
  return rt;
}


void print_table_header(GAME *tgt){
    printf("\n%d %d\n", tgt->size, tgt->nInequations);
}


void print_table_board(GAME *tgt){
  if(tgt==NULL || tgt->table==NULL) return;
  int i,j;

  for(i=0;i<tgt->size;i++){
    for(j=0;j<tgt->size;j++) printf("%d ",tgt->table[i][j]);
    printf("\n");
  }

}

void print_table_inqs(GAME *tgt){
    int i = 0;
    for(i = 0; i < tgt->nInequations; i++){
        print_inq(tgt->inequations[i]);
    }
}


void print_table(GAME *tgt){
    print_table_header(tgt);
    print_table_board(tgt);
    print_table_inqs(tgt);
}


void free_game(GAME **tgt){
  if(tgt==NULL || *tgt==NULL) return;
  int i;


  free((*tgt)->possible_values);

  for(i=0;i<(*tgt)->nInequations;i++)
    free_inq(&(*tgt)->inequations[i]);


  for(i=0;i<(*tgt)->size;i++)
    free((*tgt)->table[i]);

  free((*tgt)->table);
  free(*tgt);
}
