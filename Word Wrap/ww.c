#include "ww.h"

extern int lineSize, nWords, *spacesVector, *linesVector;


void solveWordWrap (int sizes[]){
  int extras[nWords+1][nWords+1]; 
  int lineCost[nWords+1][nWords+1];
  int totalCost[nWords+1];
  int *aSequence=(int *)malloc((nWords+1)*sizeof(int));
  int i, j;
  for (i = 1; i <= nWords; i++){
    extras[i][i] = lineSize - sizes[i-1];
    for (j = i+1; j <= nWords; j++)
      extras[i][j] = extras[i][j-1] - sizes[j-1] - 1;
  }
  
  for (i = 1; i <= nWords; i++){
    for (j = i; j <= nWords; j++){
      if (extras[i][j] < 0)
        lineCost[i][j] = INT_MAX;
      else if (j == nWords && extras[i][j] >= 0)
        lineCost[i][j] = 0;
      else
        lineCost[i][j] = extras[i][j]*extras[i][j];
    }
}

  totalCost[0] = 0;
  for (j = 1; j <= nWords; j++){
    totalCost[j] = INT_MAX;
    for (i = 1; i <= j; i++){
      if (totalCost[i-1] != INT_MAX && lineCost[i][j] != INT_MAX && (totalCost[i-1] + lineCost[i][j] < totalCost[j])){
        totalCost[j] = totalCost[i-1] + lineCost[i][j];
        aSequence[j] = i;
      }
    }
  }

  printSolution(aSequence, nWords);

}

