#include "node.h"

NODE *newNode(){
  NODE *rt;
  rt=(NODE *)malloc(sizeof(NODE));
  if(rt!=NULL){
    rt->name=NULL;
    rt->color=BLANK;
    rt->nxt=NULL;
    return rt;
  }
  return NULL; 
}



void freeNode(NODE **tgt){
  if(tgt==NULL || *tgt==NULL) return;
  free((*tgt)->name);
  free(*tgt);
}



void plugNode(NODE *tgt, char *name){
  NODE *aux, *add=newNode();
  aux=tgt;
  add->name=name;
  while(aux->nxt!=NULL) aux=aux->nxt;
  
  add->nxt=aux->nxt;
  aux->nxt=add;
}



NODE *popNode(NODE *tgt){
  NODE *aux=tgt->nxt;
  tgt->nxt=aux->nxt;
  aux->nxt=NULL;
  return aux;
}


void printNode(NODE *tgt){
  if(tgt==NULL) return;
  printf("Name:%s\n Color:%d\n", tgt->name, tgt->color);
}


void printAllNodes(NODE *start){
  if(start->color==HEADER) return;
  printNode(start);
  printAllNodes(start->nxt);
  
}

void paintNode(NODE *tgt, int color){
  if(tgt!=NULL && color>=-2)  tgt->color=color;
}
