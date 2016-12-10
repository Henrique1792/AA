#include "ww.h"

extern int lineSize, nWords;

char *filename = NULL;

/* Logo */
void startup(){
    printf("\n");
    printf("## # #   ###   ####   ####   ## # #  ####   ###    #### \n");
    printf("## # #  ##  #  ##  #  ##  #  ## # #  ##  #  ## #   ##  #\n");
    printf("## # #  ##  #  ####   ##  #  ## # #  ####   #####  #### \n");
    printf(" #####   ###   ##  #  ####    #####  ##  #  ##   # ##   \n");
    printf("Word-Wrap with dynamic programming v1.0\n");
    printf("by meist3r-ed, freitash\n");
    printf("\n");
}

/* Reads the filename to be opened */
char *readFilename(){
    char *filename = (char *) malloc(128 * sizeof(char));

    printf(">Digite o nome do arquivo: ");
    fgets(filename, 128, stdin);
    if(filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    return filename;
}

int main(){
    FILE *file = NULL;

    startup();

    /* Opens file */
    filename = readFilename();
    file = openFile(filename);

    if(file != NULL){
        int *sizes;
        getParameters(file);
        sizes = getWordSizes(file);
        solveWordWrap(sizes);
        free(sizes);
        closeFile(file);
    }

    free(filename);
    return 0;
}
