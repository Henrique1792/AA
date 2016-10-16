#include "brute.h"

#define MAX_ITER 1000000

/* Referencia para as variaveis globais em testmain.c */
extern GAME *mask;
extern GAME *curGame;

int line = 0;
int column = -1;

/* Contador de iteracoes */
int iter_count = 0;

int brute_force_iter(){
    column = column + 1;

    if(column == curGame->size){
      column = 0;
      line = line + 1;
    }

    if(line == curGame->size) return SUCCESS;

    if(mask->table[line][column] == 0){
        //printf("nom");
        int i;
        for(i = 1; i <= curGame->size; i++){
            curGame->table[line][column] = i;
            if(check_line(line) && check_column(column)
                && check_inequations(line, column) && brute_force_iter())
                return SUCCESS;
        }

        curGame->table[line][column] = 0;
        column = column - 1;
        if(column < 0){
           column = curGame->size - 1;
           line = line - 1;
        }
        return FAIL;
    }
    else{
        //printf("m");
        return brute_force_iter();
    }
}

void brute_force(){
    if(curGame == NULL) return;
    brute_force_iter();
}

void Look_Ahead(GAME *tgt);
void MVR(GAME *tgt);
