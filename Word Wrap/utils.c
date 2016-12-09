#include "utils.h"

int lineSize, nWords, *wordSequence, jump;
/*
 * spacesVector = control spaces inside the line
 * linesVector = control linesums 2 reach minimal sum.
*/

/*Open 'filename' File
 *return: File || NULL
 *
*/
FILE *openFile(char *fileName){
  if(fileName==NULL) return NULL;
  FILE *rt = fopen(fileName, "r");
  return rt;
}

/*Close 'tgt' file
 *No Return Value
 *
*/
void closeFile(FILE *tgt){
  if(tgt==NULL) return;
  fclose(tgt);
}

/*Read a line from file tgt
 *return: Line if succes  
 *        NULL otherwise
*/
char *readFileLine(FILE *tgt){
  char *line=(char *)malloc(sizeof(char));
  if(tgt){
    int n=0;
    char buffer=' ';
    buffer=fgetc(tgt);

    if(buffer!='\n' && buffer!=EOF){
      do{
        line[n++]=buffer;
        line=(char *)realloc(line, sizeof(char*)*(n+1));
        buffer=fgetc(tgt);
      }while(buffer!='\n' && buffer!=EOF);
      line[n]='\0';
      return line;
    }
  }
  free(line);
  return NULL;
}


/*
 *Get nWords and lineSize from 
 *tgt file
 *return: 1 if success.
 *        0 otherwise.
*/
int getParameters(FILE *tgt){
  if(tgt==NULL) return 0;
  rewind(tgt);
  lineSize=atoi(readFileLine(tgt));
  nWords=atoi(readFileLine(tgt));
  return 1; 
}


/*
 *Get all sizes from words
 *parameter: file
 *
 *returns vector with word sizes.
*/
int *getWordSizes(FILE *tgt){
  int *rt=NULL,i=0,j;
  char *tmp=NULL;
 
  while(!feof(tgt)){
    tmp=readFileLine(tgt);
    j=0;
    if(tmp!=NULL){
      rt=(int *)realloc(rt, (i+1)*sizeof(int));
      while(tmp[j]!='\0') j++;
      rt[i++]=j;
      free(tmp);
    }
  }
  rt[i]=(int)'\0';
  return rt;
}


/*
 * Print Solution obtained in ww.c: solveWordWrap()
 * args: p vector with solution sequence
 *       Total of words n.
*/
  int printSolution (int answer[], int n){
  int k;
  if (answer[n] == 1)
    k = 1;
  else
    k = printSolution (answer, answer[n]-1) + 1;
  printf ("Line number %d: From word no. %d to %d \n", k, answer[n], n);
  wordSequence=(int *)realloc(wordSequence,(jump+2)*sizeof(int));
  wordSequence[jump++]=answer[n];
  wordSequence[jump++]=n;
  return k;
}



void output(FILE *tgt){
  int i,j;
  char *tmp;
  for(i=0;i<nWords;i++){
      for(j=i;j<=wordSequence[i];j++){
        tmp=readFileLine(tgt);
        if(tmp!=NULL){
          printf("%s ",tmp);
          free(tmp);
        }
      }
      printf("\n");
  }
}
