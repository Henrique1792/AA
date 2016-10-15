#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "files.h"
#include "table.h"



/* Logo */
void startup(){
    printf("\n");
    printf("####  ## #  ####  ####   ###  ## #  ##  ##  #  ##\n");
    printf("##    ## #   ##   ## #  ###   ## #  ##  ## #   ##\n");
    printf("###   ## #   ##   ## #   ###  ####  ##  ####   ##\n");
    printf("##     ###   ##   ####  ###   ## #  ##  ##  #  ##\n");
    printf("Futoshiki solver v0.1\n");
    printf("by meist3r-ed, freitash\n");
    printf("\n");
}

/* Le o nome do arquivo a ser aberto */
char *readFilename(){
    char *filename = (char *) malloc(128 * sizeof(char));

    printf(">Digite o nome do arquivo: ");
    fgets(filename, 128, stdin);
    if(filename[strlen(filename) - 1] == '\n')
        filename[strlen(filename) - 1] = '\0';

    return filename;
}

/* Executa operacoes de leitura no arquivo aberto */
void readController(FILE *file){
    int numCases = 0, count = 0;
    int *tableConfig = NULL;
    GAME *curGame = NULL;

    numCases = readNumberOfCases(file);

    while(count < numCases){
        tableConfig = readTableConfig(file);
        curGame = readGameTable(tableConfig[0], tableConfig[1], file);

        print_table(curGame);
        free_game(&curGame);
        free(tableConfig);

        readLine(file);
        count = count + 1;
    }
}

/* Loop principal */
int main(){
    FILE *file = NULL;
    char *filename = NULL;

    startup();

    /* Abre o arquivo */
    filename = readFilename();
    file = openFile(filename);

    readController(file);

    /* Fecha o arquivo */
    closeFile(file);

    free(filename);

    return 0;
}
