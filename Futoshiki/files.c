#include <stdio.h>
#include <stdlib.h>

#include "files.h"
#include "table.h"

/* Abrir arquivo */
/* Argumentos *filename (nome do arquivo) */
/* Retorno: *newFile (arquivo aberto) || NULL (erro) */
FILE *openFile(char *filename){
    printf("\n");
    if(filename){
        FILE *newFile = fopen(filename, "r");
        if(newFile){
            printf(">Arquivo aberto com sucesso.");
            fseek(newFile, 0, SEEK_SET);
        }
        else{
            printf(">Arquivo inexistente ou erro ao abrir");
        }
        return newFile;
    }
    printf(">Nome de arquivo eh nulo");
    return NULL;
}

/* Read line */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: *line (linha lida) || NULL (erro) */
char *readLine(FILE *stream){
    if(stream){
        int n = 0;
        char buffer = ' ';
        char *line = (char *) malloc(sizeof(char));

        buffer = fgetc(stream);
        if(buffer != '\n' && buffer != EOF){
            do{
                line[n] = buffer;
                n = n + 1;
                line = realloc(line, sizeof(char *) * n + 1);
                buffer = fgetc(stream);
            }while(buffer != '\n' && buffer != EOF);
            line[n] = '\0';

            return line;
        }

        free(line);
    }
    return NULL;
}

/* Ler numero de casos */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: result (numero de casos) || -1 (erro) */
int readNumberOfCases(FILE *stream){
    if(stream){
        char *line = NULL;
        line = readLine(stream);

        if(line){
            int result = 0;

            result = atoi(line);
            free(line);

            return result;
        }

        free(line);
    }
    return -1;
}

/* Ler configuracao da tabela */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: *config ([0]: tamanho da tabela, [1]: numero de inequacoes) || NULL (erro) */
int *readTableConfig(FILE *stream){
    if(stream){
        char *line = NULL;
        line = readLine(stream);

        if(line){
            int *config = (int *) malloc(2 * sizeof(int));

            config[0] = atoi(strtok(line, " \n"));
            config[1] = atoi(strtok(NULL, " \n"));
            free(line);

            return config;
        }

        free(line);
    }
    return NULL;
}


/* Ler tabuleiro */
/* Argumentos: size (tamanho do tabuleiro), nInequations (numero de inequacoes), *stream (arquivo de origem) */
/* Retorno: *newGame(jogo lido) || NULL (erro) */
GAME *readGameTable(int size, int nInequations, FILE *stream){
    if(stream && size > 0 && nInequations >= 0){
        char *curLine = NULL;
        GAME *newGame = NULL;
        newGame = create_game(size, nInequations);

        int i = 0, j = 0;
        for(i = 0; i < size; i++){
            curLine = readLine(stream);

            newGame->table[i][j] = atoi(strtok(curLine, " "));
            j = j + 1;
            while(j < size){
                newGame->table[i][j] = atoi(strtok(NULL," \n"));
                j = j + 1;
            }
            j = 0;

            free(curLine);
        }

        i = 0;
        for(i = 0; i < nInequations; i++){
            curLine = readLine(stream);

            newGame->inequations[i].x1 = atoi(strtok(curLine, " "));
            newGame->inequations[i].y1 = atoi(strtok(NULL, " "));
            newGame->inequations[i].x2 = atoi(strtok(NULL, " "));
            newGame->inequations[i].y2 = atoi(strtok(NULL, " "));

            free(curLine);
        }

        return newGame;
    }
    return NULL;
}

/* Fechar arquivo */
/* Argumentos: *stream (arquivo de origem) */
/* Retorno: nenhum */
void closeFile(FILE *file){
    printf("\n");
    if(file != NULL){
        fclose(file);
        printf(">Arquivo fechado com sucesso\n");
    }
}
