#include "ww.h"

extern int lineSize, nWords, *spacesVector, *linesVector;


void solveWordWrap (int l[]){
	int extras[nWords+1][nWords+1]; 
	int lc[nWords+1][nWords+1];
	int c[nWords+1];
	int *p=(int *)malloc((nWords+1)*sizeof(int));
	int i, j;
	for (i = 1; i <= nWords; i++){
		extras[i][i] = lineSize - l[i-1];
		for (j = i+1; j <= nWords; j++)
			extras[i][j] = extras[i][j-1] - l[j-1] - 1;
	}

	for (i = 1; i <= nWords; i++){
		for (j = i; j <= nWords; j++){
			if (extras[i][j] < 0)
				lc[i][j] = INT_MAX;
			else if (j == nWords && extras[i][j] >= 0)
				lc[i][j] = 0;
			else
				lc[i][j] = extras[i][j]*extras[i][j];
		}
	}

	c[0] = 0;
	for (j = 1; j <= nWords; j++){
		c[j] = INT_MAX;
		for (i = 1; i <= j; i++){
			if (c[i-1] != INT_MAX && lc[i][j] != INT_MAX && (c[i-1] + lc[i][j] < c[j])){
				c[j] = c[i-1] + lc[i][j];
				p[j] = i;
			}
		}
	}
  
	printSolution(p, nWords);
}

