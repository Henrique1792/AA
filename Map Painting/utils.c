#include "utils.h"


FILE *openFile(char *tgt){
  if(tgt==NULL) return NULL;
  FILE *rt=fopen(tgt,"r");

  if(rt)
    printf("File open successful\n");
  else 
    printf("Failed to open %s\n",tgt);
  return rt;
}

void closeFile(FILE *tgt){
 tgt != NULL ? fclose(tgt) : printf("No file for closing\n") ;
}



char *readLine(FILE *tgt){
  if(tgt==NULL)  return NULL;
  char *rt=(char *)malloc(sizeof(char)), step=' ';
  int i=0;
  

  step=fgetc(tgt);
  if(step!='\n' && step!=EOF){
    do{
      rt[i++]=step;
      rt=(char *)realloc(rt, (i+1)*sizeof(char));
      step=fgetc(tgt);
    }while(step!='\n' && step!=EOF);
    rt[i]='\0';
    return rt;
  }
  free(rt);
  return NULL;
}


int readInt(FILE *tgt){
  if(tgt){
    int rt;
    char *value=readLine(tgt);
    if(value!=NULL){
      rt=atoi(value);
      free(value);
      return rt;
    }
  }
  return INT_MIN; 
}
