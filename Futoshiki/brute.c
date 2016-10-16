#include "brute.h"

#define MAX_ITER 1000000

/* Referencia para as variaveis globais em testmain.c */
extern GAME *mask;
extern GAME *curGame;

/* Contador de iteracoes */
int iter_count = 0;

int brute_force_iter(int line, int column){
    if(column >= curGame->size){
        column = 0;
        line = line + 1;
    }

    if(line == curGame->size) return SUCCESS;

    if(mask->table[line][column] != 0) return brute_force_iter(line, column + 1);

    int i = 1;
    for(i = 1; i <= curGame->size; i++){
        curGame->table[line][column] = i;

        if((check_line(line) && check_column(column)
            && check_inequations(line, column)) && brute_force_iter(line, column + 1))
            return SUCCESS;
    }

    curGame->table[line][column] = mask->table[line][column];

    return FAIL;
}

void brute_force(){
    if(curGame == NULL) return;
    brute_force_iter(0, 0);
}

void Look_Ahead(GAME *tgt);
void MVR(GAME *tgt);
