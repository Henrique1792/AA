#include "brute.h"

#define MAX_ITER 1000000

/* Referencia para as variaveis globais em testmain.c */
extern GAME *mask;
extern GAME *curGame;
extern int *value;


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

    if(mask->table[line][column] != 0) return brute_force_iter();

    int i = 1;
    for(i = 1; i <= curGame->size; i++){
        curGame->table[line][column] = i;

        if((check_line(line) && check_column(column)
            && check_inequations(line, column)) && brute_force_iter())
            return SUCCESS;
    }

    curGame->table[line][column] = mask->table[line][column];

    column = column - 1;
    if(column < 0){
       column = curGame->size - 1;
       line = line - 1;
    }

    return FAIL;
}

void brute_force(){
    if(curGame == NULL) return;
    brute_force_iter();
}


/*Look Ahead*/

int Look_Ahead_iter(){


}

void Look_Ahead(){
  if(curGame==NULL) return;
  Look_Ahead_iter();
}


/*MVR*/
int MVR_iter(){


}

void MVR(){
  if(curGame==NULL) return;
  MVR_iter();
}
