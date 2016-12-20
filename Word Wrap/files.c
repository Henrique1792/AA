#include "files.h"
/*Open 'filename' File
 *return: File || NULL
 *
*/
FILE *openFile(char *filename){
    printf("\n");
    if(filename){
        FILE *newFile = fopen(filename, "r");
        if(newFile){
            printf(">Arquivo aberto com sucesso.\n");
            fseek(newFile, 0, SEEK_SET);
        }
        else{
            printf(">Arquivo inexistente ou erro ao abrir.\n");
        }
        return newFile;
    }
    printf(">Nome de arquivo eh nulo.\n");
    return NULL;
}

/*Close 'tgt' file
 *No Return Value
 *
*/
void closeFile(FILE *file){
    printf("\n");
    if(file != NULL){
        fclose(file);
        printf(">Arquivo fechado com sucesso\n");
    }
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
        buffer = fgetc(tgt);

        if(buffer != '\n' && buffer != EOF){
            do{
                line[n++] = buffer;
                line=(char *)realloc(line, sizeof(char)*(n+1));
                buffer = fgetc(tgt);
            }while(buffer != '\n' && buffer != EOF);
            line[n] = '\0';
            return line;
        }
    }
    free(line);
    return NULL;
}
