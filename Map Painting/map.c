#include "map.h"

MAP *newMap(int colors, int map_size){
  if(colors<=0 || map_size<=0) return NULL;
  MAP *rt=(MAP *)malloc(sizeof(MAP));
  int i;
  if(rt!=NULL){
    rt->headers=(NODE **)malloc(map_size*sizeof(NODE *));
    for(i=0;i<map_size;i++){
      rt->headers[i]=newNode();
      rt->headers[i]->header=HEADER;
    }
    rt->colors=colors;
    rt->map_size=map_size;
    rt->nEdges=(int *)malloc(map_size*sizeof(int));
  }
  return rt;
}


void mapStartUp(MAP **tgt, FILE *aux){
  int colors, map_size,i,j;
  map_size=readInt(aux);
  colors=readInt(aux);
  NODE *walk;
  *tgt=newMap(colors, map_size);
  
  for(j=0;j<map_size;j++){
    (*tgt)->headers[j]->name=readLine(aux);
    (*tgt)->nEdges[j]=readInt(aux);
    walk=(*tgt)->headers[j];
    
    for(i=0;i<(*tgt)->nEdges[j];i++){
      plugNode(walk, readLine(aux));
      walk=walk->nxt;
    }
    walk->nxt=(*tgt)->headers[j];
  }
  closeFile(aux);
}

void printMap(MAP *tgt){
  int i;
  printf("Map_Size: %d\n Colors: %d\n",tgt->map_size, tgt->colors);  
  for(i=0;i<tgt->map_size;i++){
   printf("HEADER:\n");
   printNode(tgt->headers[i]);
     printf("EDGES\n");
   printAllNodes(tgt->headers[i]->nxt);
  }
}

void freeMap(MAP **tgt){
  if(tgt==NULL || *tgt==NULL) return;
  int i=0;
  NODE *aux=NULL; 
  
  for(i=0;i<((*tgt)->map_size);i++){
      aux=popNode((*tgt)->headers[i]);
      while(!IsHeader(aux->header)){
        freeNode(&aux);
        aux=popNode((*tgt)->headers[i]);
      };
      freeNode(&aux);
  }
  
  free((*tgt)->nEdges);
  free((*tgt)->headers);
  free(*tgt);
}

void paintRecursive(MAP *tgt, int method){
  int i;
  if(method==0){
    
    
  }
  else if(method==1){}
  else if(method==2){}
}


void paintMapBruteForce(MAP **tgt){
  return paintRecursive(*tgt,0);
}

void paintMapMVR(MAP **tgt){
  return paintRecursive(*tgt,1);
}

void paintMapLookAhead(MAP **tgt){
  return paintRecursive(*tgt,2);
}

