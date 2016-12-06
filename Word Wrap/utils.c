#include "utils.h"
#define SQR(x) x*x

int lineSize, nWords, *spacesVector, *linesVector;
/*
 * spacesVector = control spaces inside the line
 * linesVector = control linesums 2 reach minimal sum.
 *
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