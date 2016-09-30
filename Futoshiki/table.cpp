#include "table.h"
#include <stdlib.h>
#define DEFAULT -1




Restriction *create_Restriction(){
  Restriction *rt=(Restriction *)malloc(sizeof(Restriction));
  cin >> rt->x1>> rt->x2>> rt->y1>> rt->y2;
  return rt;
}

void free_restriction(Restriction **tgt){
  free(*tgt);
  free(tgt);
}


Table::Table(int size,int nRestrictions){
  this->nRestrictions=nRestrictions;
  this->size=size;
  int i,j;

  //Building initial matrix
  this->board=(int **)malloc(size*sizeof(int *));
    for(j=0;j<size;j++){
      this->board[j]=(int *)malloc(size*sizeof(int));
    }
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      this->board[i][j]=DEFAULT;
    }
  }

  //set restrictions.
  
  for(this->Restriction_check=this->Restricted->begin();
      this->Restricted->size()<nRestrictions;
      this->Restriction_check++){
 
    /*
     * Things to pay attention: Allocate each <Restriction>
     * values and set them to 
     *
     *
     *
     *
     * */

  
  
  }


}


Table::~Table(){
  int i;

  for(i=0;i<this->size;i++)
    free(this->board[i]);
  free(this->board);
  //int i;
  //for(i=this->nRestrictions-1;i>-1;i--) free(&Restricted[i]);
}




void Table::print_table(){
  int i,j;

  for(i=0;i<this->size;i++){
    for(j=0;j<this->size;j++) cout<<this->board[i][j];
  cout<<"\n";
  }

}
