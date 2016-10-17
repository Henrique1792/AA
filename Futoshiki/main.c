#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "files.h"
#include "table.h"
#include "brute.h"

/* JOGO ATUAL / MASK */
GAME *mask = NULL;

/* BOARD PARA SOLUCOES */
GAME *curGame = NULL;

/* TIPO DE OPERACAO */
/* 1 = backtracking simples */
/* 2 = backtracking + MVR */
/* 3 = backtracking + MVR + Lookahead */
int optype = 1;

/* OPERADOR DE EXIBICAO */
/* 0 = fechar arquivo */
/* 1 = mostrar proximo */
/* 2 = mostrar tudo */
int opex = 0;

/* ARQUIVO ATUALMENTE ABERTO */
char *filename = NULL;

/* ARQUIVO DE TIMESTAMPS */
FILE *timestamps = NULL;

/* Logo */
void startup(){
    printf("\n");
    printf("####  ## #  ####  ####   ###  ## #  ##  ##  #  ##\n");
    printf("##    ## #   ##   ## #  ###   ## #  ##  ## #   ##\n");
    printf("###   ## #   ##   ## #   ###  ####  ##  ####   ##\n");
    printf("##     ###   ##   ####  ###   ## #  ##  ##  #  ##\n");
    printf("Futoshiki solver v0.7\n");
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
    clock_t start_t, end_t, total_t;
    float delta_t = 0.0, avg = 0.0;

    int *tableConfig = NULL;

    numCases = readNumberOfCases(file);

    switch(optype){
        case 1:
            printf("\n>Backtracking simples:\n\n");
            timestamps = fopen("times_brute.dat", "w+");
            break;
        case 2:
            printf("\n>Backtracking + MVR:\n\n");
            timestamps = fopen("times_mvr.dat", "w+");
            break;
        case 3:
            printf("\n>Backtracking + MVR + Look-Ahead:\n\n");
            timestamps = fopen("times_la.dat", "w+");
            break;
    }

    if(optype >= 1 && optype <= 3)
        fprintf(timestamps, "[%s]:\n\n", filename);

    while(count < numCases){
        tableConfig = readTableConfig(file);
        mask = readGameTable(tableConfig[0], tableConfig[1], file);
        curGame = copy_game(mask);

        start_t = clock();

        printf("\n[%d]: ", count + 1);

        fprintf(timestamps, "[%d]: ", count + 1);
        switch(optype){
            case 1:
                brute_force();
                break;
            case 2:
                //mvr();
                break;
            case 3:
                look_ahead();
                break;
        }

        end_t = clock();
        delta_t = ((float)(end_t - start_t) / 1000000.0F ) * CLOCKS_PER_SEC;

        if(optype >= 1 && optype <= 3)
            fprintf(timestamps, "%fs\n", delta_t);
            avg = avg + delta_t;
            print_table_board(curGame);
            printf("Tempo de execucao: %fs\n", delta_t);

        free_game(&mask);
        free_game(&curGame);
        free(tableConfig);

        readLine(file);
        count = count + 1;
    }

    if(optype >= 1 && optype <= 3)
        fprintf(timestamps, "\n[Average]: %fs\n", avg / count);
        fclose(timestamps);
}

/* Loop principal */
int main(int argc, char *argv[]){
    FILE *file = NULL;

    startup();

    /* Abre o arquivo */
    filename = readFilename();
    file = openFile(filename);

    if(argc > 1)
        if(atoi(argv[1]) >= 1 && atoi(argv[1]) <= 3)
            optype = atoi(argv[1]);

    readController(file);

    /* Fecha o arquivo */
    closeFile(file);

    free(filename);

    return 0;
}
