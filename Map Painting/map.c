#include "map.h"

MAP *newMap(int colors, int map_size){
  if(colors<=0 || map_size<=0) return NULL;
  MAP *rt=(MAP *)malloc(sizeof(MAP));
  int i;
  if(rt!=NULL){
    rt->header=(NODE **)malloc(map_size*sizeof(NODE *));
    for(i=0;i<map_size;i++){
      rt->header[i]=newNode();
      rt->header[i]->color=HEADER;
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
    (*tgt)->header[j]->name=readLine(aux);
    (*tgt)->nEdges[j]=readInt(aux);
    walk=(*tgt)->header[j];
    
    for(i=0;i<(*tgt)->nEdges[j];i++){
      plugNode(walk, readLine(aux));
      walk=walk->nxt;
    }
    walk->nxt=(*tgt)->header[j];
  }
  closeFile(aux);
}

void printMap(MAP *tgt){
  int i;
  printf("Map_Size: %d\n Colors: %d\n",tgt->map_size, tgt->colors);  
  for(i=0;i<tgt->map_size;i++){
   printf("HEADER:\n");
   printNode(tgt->header[i]);
     printf("EDGES\n");
   printAllNodes(tgt->header[i]->nxt);
  }
}

void freeMap(MAP **tgt){
  if(tgt==NULL || *tgt==NULL) return;
  int i=0;
  NODE *aux=NULL; 
  
  for(i=0;i<((*tgt)->map_size);i++){
      aux=popNode((*tgt)->header[i]);
      while(aux->color!=HEADER){
        freeNode(&aux);
        aux=popNode((*tgt)->header[i]);
      };
      freeNode(&aux);
  }
  
  free((*tgt)->nEdges);
  free((*tgt)->header);
  free(*tgt);
}

void paintRecursive(MAP *tgt, int method){
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

