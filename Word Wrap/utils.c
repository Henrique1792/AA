#include "utils.h"

int line_size=0, nWords=0;
/*Open 'filename' File
 *return: File || NULL
 *
*/

FILE *open_file(char *fileName){
  if(fileName==NULL) return NULL;
  FILE *rt = fopen(fileName, "r");
  return rt;
}

/*Close 'tgt' file
 *No Return Value
 *
*/
void close_file(FILE *tgt){
  if(tgt==NULL) return;
  free(tgt);
}

/*Read a line from file tgt
 *return: Line || NULL
 * */
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



int get_parameters(FILE *tgt){
  if(tgt==NULL) return 0;
  rewind(tgt);
  line_size=atoi(readFileLine(tgt));
  nWords=atoi(readFileLine(tgt));
  return 1; 
}
