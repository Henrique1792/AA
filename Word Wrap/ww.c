#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ww.h"

extern int lineSize, nWords;
extern char *filename;

/*
 * Print Solution obtained in solveWordWrap()
 * args: p vector with solution sequence
 *       Total of words n.
 *
 *       THIS METHOD IS MESSED UP DUE TO RECURSION.
*/
int printSolution (int *answer, int n){
    int k;
    if (answer[n] == 1)
        k = 1;
    else
        k = printSolution (answer, answer[n] - 1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, answer[n], n);
    return k;
}
/*
 * This algorithm will solve
 * Word Wrapping.
*/
void solveWordWrap (int *sizes){
    int extras[nWords+1][nWords+1];
    int lineCost[nWords+1][nWords+1];
    int totalCost[nWords+1];
    int *aSequence = (int *) malloc((nWords+1)*sizeof(int));
    int i, j, k;

    // calculate extra spaces in a single line.  The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line

    for(k = 0; k < nWords + 1; k++)
        aSequence[k]=0;

    for (i = 1; i <= nWords; i++){
        extras[i][i] = lineSize - sizes[i-1];
        for (j = i + 1; j <= nWords; j++)
            extras[i][j] = extras[i][j-1] - sizes[j-1] - 1;
    }

    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lineCost[i][j] indicates cost of putting words from
    // word number i to j in a single line

    for (i = 1; i <= nWords; i++){
        for (j = i; j <= nWords; j++){
            if (extras[i][j]<0) lineCost[i][j] = INT_MAX;
            else if (j == nWords && extras[i][j] >= 0)
            lineCost[i][j] = 0;
            else
            lineCost[i][j] = extras[i][j]*extras[i][j];
        }
    }
    // Calculate minimum cost and find minimum cost arrangement.
    //  The value totalCost[j] indicates optimized cost to arrange words
    // from word number 1 to j.

    clock_t start_t, end_t, total_t;
    float delta_t = 0.0, avg = 0.0;
    FILE *dump = NULL;

    dump = fopen("dump.txt", "a+");
    if(dump == NULL){
        printf("> Erro ao abrir arquivo de dump, execucao sem log");
    }
    else{
        fseek(dump, 0, SEEK_END);
    }

    start_t = clock();

    totalCost[0] = 0;
    for (j = 1; j <= nWords; j++){
        totalCost[j] = INT_MAX;
        for (i = 1; i <= j; i++){
            if (totalCost[i-1] != INT_MAX && lineCost[i][j] != INT_MAX
                && (totalCost[i-1] + lineCost[i][j] < totalCost[j])){
                totalCost[j] = totalCost[i-1] + lineCost[i][j];
                aSequence[j] = i;
            }
        }
    }

    end_t = clock();
    delta_t = ((float)(end_t - start_t) / 1000000.0F ) * CLOCKS_PER_SEC;

    if(dump != NULL){
        fprintf(dump, "%s %f\n", filename, delta_t);
        fclose(dump);
    }

    printSolution(aSequence, nWords);
    free(aSequence);
}
