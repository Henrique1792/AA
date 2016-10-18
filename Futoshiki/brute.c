#include "brute.h"

#define MAX_ITER 1000000

/* Referencia para as variaveis globais em testmain.c */
extern GAME *mask;
extern GAME *curGame;
int **auxboard;

extern optype;

extern FILE *timestamps;

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
        iter_count = iter_count + 1;

        if(iter_count >= MAX_ITER){
            return FAIL;
        }

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

    if(brute_force_iter(0, 0) == FAIL){
        printf("\n>TIMEOUT");
        fprintf(timestamps, "(T) ");
    }

    fprintf(timestamps, "%dits, ", iter_count);
    iter_count = 0;
}

/* int type: 1: decrement, 2: increment*/
void updateAuxMatrix(int line, int column, int type){
    int i = 0;
    for(i = 0; i < mask->size; i++){
        if(type == 1)
            auxboard[line][i]--;
        else
            auxboard[line][i]++;
    }

    i = 0;
    for(i = 0; i < mask->size; i++){
        if(i != line)
            if(type == 1)
                auxboard[i][column]--;
            else
                auxboard[i][column]++;
    }
}

int LookAhead_iter(int line, int column){
    int i;
    //Reach end of line.
    if(column >= curGame->size){
        column = 0;
        line++;
    }

    //Reach end of Game
    if(line == curGame->size) return SUCCESS;

    //Find an value set by user.
    if(mask->table[line][column] != 0)
        return LookAhead_iter(line, column + 1);

    //All Possibilities were used.
    if(auxboard[line][column] == 0){
        updateAuxMatrix(line, column, 2);
        return FAIL;
    }

    //Check Line, Column, possible Inequations
    for(i = 1; i<=curGame->size; i++){
        curGame->table[line][column] = i;

        if(iter_count >= MAX_ITER){
            return FAIL;
        }

        if(check_line(line) && check_column(column)){
            iter_count = iter_count + 1;

            if((check_inequations(line, column)) && LookAhead_iter(line, column + 1)){
                updateAuxMatrix(line, column, 1);
                return SUCCESS;
            }
        }
    }

    //Set Current value to it's mask.
    curGame->table[line][column] = mask->table[line][column];

    return FAIL;
}

void look_ahead(){
    if(curGame == NULL) return;
    int i,j;
    auxboard = (int **) malloc(curGame->size * sizeof(int *));

    for(i=0; i<curGame->size; i++)
        auxboard[i] = (int *) malloc(curGame->size * sizeof(int));
    for(i=0; i<curGame->size; i++){
        for(j=0; j<curGame->size; j++){
            auxboard[i][j] = curGame->size;
            if(mask->table[i][j] != 0)
                updateAuxMatrix(i, j, 1);
        }
    }

    if(optype == 2){
        if(LookAhead_iter(0, 0) == FAIL){
            printf("\n>TIMEOUT");
            fprintf(timestamps, "(T) ");
        }
    }
    else if(optype == 3){
        if(MVR(0, 0) == FAIL){
            printf("\n>TIMEOUT");
            fprintf(timestamps, "(T) ");
        }
    }

    fprintf(timestamps, "%dits, ", iter_count);

    iter_count = 0;

    for(i=0;i<curGame->size;i++)
        free(auxboard[i]);
    free(auxboard);
}

int checkMVREnd(){
    int i = 0, j = 0, mark = 0;
    for(i = 0; i < mask->size; i++){
        for(j = 0; j < mask->size; j++){
            if(mask->table[i][j] == 0)
                if(auxboard[i][j] > 0)
                    mark = 1;
        }
    }

    if(mark == 1) return FAIL;
    else return SUCCESS;
}

int MVR(int line, int column){
    if(checkMVREnd() == SUCCESS) return SUCCESS;

    //All Possibilities were used.
    if(auxboard[line][column] == 0){
        updateAuxMatrix(line, column, 2);
        return FAIL;
    }

    int i = 0, j = 0;
    int nextX = line, nextY = column;

    for(i = 0; i < mask->size; i++){
        for(j = 0; j < mask->size; j++){
            if(i != line || j != column){
                if(curGame->table[i][j] == 0){
                    if(auxboard[i][j] > 0 && auxboard[i][j] <= auxboard[nextX][nextY]){
                        nextX = i;
                        nextY = j;
                    }
                }
            }
        }
    }

    if(nextX == line && nextY == column) return FAIL;

    //Check Line, Column, possible Inequations
    for(i = 1; i<=curGame->size; i++){
        curGame->table[nextX][nextY] = i;

        if(iter_count >= MAX_ITER){
            return FAIL;
        }

        if(check_line(nextX) && check_column(nextY)){
            iter_count = iter_count + 1;

            print_table_board(curGame);

            if((check_inequations(nextX, nextY)) && MVR(nextX, nextY)){
                updateAuxMatrix(nextX, nextY, 1);
                return SUCCESS;
            }
        }
    }

    //Set Current value to it's mask.
    curGame->table[nextX][nextY] = mask->table[nextX][nextY];

    return FAIL;
}
