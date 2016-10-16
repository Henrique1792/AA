#include "rules.h"

/* Referencia para as variaveis globais em testmain.c */
extern GAME *mask;
extern GAME *curGame;

int compare_vectors(int *v1, int *v2, int size){
    int k;

    for(k=0; k<size; k++){
        if(v1[k] != v2[k]){
            return FAIL;
        }
    }
    return SUCCESS;
}

int check_values(int *chk){
    int i = 0;
    int *count  = (int *) calloc(curGame->size + 1, sizeof(int));

    for(i = 0; i < curGame->size; i++){
        count[chk[i]] = count[chk[i]] + 1;
    }

    i = 1;
    for(i = 1; i < curGame->size + 1; i++){
        if(count[i] > 1){
            free(count);
            return FAIL;
        }
    }

    free(count);
    return SUCCESS;
}

int check_line(int line){
    if(curGame == NULL || line < 0 || line >= curGame->size)  return FAIL;

    int *chk = (int *) malloc(curGame->size * sizeof(int));
    int j = 0, result = FAIL;

    for(j = 0; j<curGame->size; j++){
        chk[j] = curGame->table[line][j];
    }

    result = check_values(chk);

    free(chk);

    return result;
}

int check_column(int column){
    if(curGame == NULL || column < 0 || column >= curGame->size)  return FAIL;

    int *chk = (int *) malloc(curGame->size * sizeof(int));
    int i = 0, result = FAIL;

    for(i = 0; i<curGame->size; i++){
        chk[i] = curGame->table[i][column];
    }

    result = check_values(chk);

    free(chk);

    return result;
}

int check_inequations(int x, int y){
    if(curGame == NULL) return FAIL;
    int i = 0;
    int x1 = 0, x2 = 0;
    int y1 = 0, y2 = 0;

    for(i = 0; i < curGame->nInequations; i++){
        x1 = mask->inequations[i].x1;
        y1 = mask->inequations[i].y1;
        x2 = mask->inequations[i].x2;
        y2 = mask->inequations[i].y2;

        if(x1 == x || x2 == x){
            if(y1 == y || y2 == y){
                if(curGame->table[x1][y1] == 0 || curGame->table[x2][y2] == 0)
                    return SUCCESS;

                if(curGame->table[x1][y1] > curGame->table[x2][y2])
                    return FAIL;
                else
                    return SUCCESS;
            }
        }
    }

    return SUCCESS;
}
