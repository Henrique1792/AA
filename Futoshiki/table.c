#include "table.h"
#include "inequation.h"

GAME *create_game(int size,int inequations){
  if(size <0 || size <4||size>9 || inequations <=0) return NULL;
  GAME *rt=(GAME *)malloc(sizeof(GAME));
  int i,j;
  rt->table=(int **)malloc(size*sizeof(int *));
  for (i=0;i<size;i++) rt->table[i]=(int *)malloc(size*sizeof(int));

  for(i=0;i<size;i++){
    for(j=0;j<size;j++)
      rt->table[i][j]=DEFAULT;
  }

  rt->possible_values=(int *)malloc(size*sizeof(int));
  for(i=0;i<size;i++) rt->possible_values[i]=i+1;


  rt->inequations=(INEQUATION *)malloc(inequations*sizeof(INEQUATION));
  rt->nInequations=inequations;

  rt->size=size;
  return rt;
}

GAME *copy_game(GAME *origin){
    if(origin){
        int i = 0, j = 0;
        GAME *copy = create_game(origin->size, origin->nInequations);

        for(i=0; i < origin->size; i++){
            for(j=0; j < origin->size; j++)
            copy->table[i][j] = origin->table[i][j];
        }

        free_inq(copy->inequations);
        copy->inequations = copy_inq(origin->inequations, origin->nInequations);

        return copy;
    }
    return NULL;
}


void print_table_header(GAME *tgt){
    printf("\n%d %d\n", tgt->size, tgt->nInequations);
}


void print_table_board(GAME *tgt){
    if(tgt==NULL || tgt->table==NULL) return;

    printf("\n");
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

  free((*tgt)->inequations);

  for(i=0;i<(*tgt)->size;i++)
    free((*tgt)->table[i]);
  free((*tgt)->table);
  free(*tgt);
}
