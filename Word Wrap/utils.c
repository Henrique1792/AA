#include "utils.h"

int lineSize, nWords, *wordSequence, jump;
/*
 *Get all sizes from words
 *parameter: file
 *
 *returns vector with word sizes.
*/
int *getWordSizes(FILE *tgt){
    int *rt =NULL;
    int i=0;
    char *tmp=NULL;

    do{
      tmp = readFileLine(tgt);
        if(tmp!=NULL){
            rt=(int *)realloc(rt, (i+1)*sizeof(int));
            rt[i++]=strlen(tmp);
            free(tmp);
        }
    }while(!feof(tgt));
    return rt;
}

/*
 *Get nWords and lineSize from
 *tgt file
 *return: 1 if success.
 *        0 otherwise.
*/
int getParameters(FILE *tgt){
    rewind(tgt);
    char *tmp;

    tmp = readFileLine(tgt);
    lineSize = atoi(tmp);
    free(tmp);

    tmp = readFileLine(tgt);
    nWords = atoi(tmp);
    free(tmp);

    return 1;
}

/*
 * Alloc Matrix
 *
*/
int **getMatrix(int size){
    if(size<=0) return NULL;
    int i, **rt;
    rt = (int **)malloc(size*sizeof(int));

    for(i=0;i<size;i++)
        rt[i] = (int *) malloc(size*sizeof(int));

    return rt;
}
/*
 * free pre-alocated matrix
 *
 *
*/
void freeMatrix(int **tgt, int size){
    if(tgt==NULL || *tgt==NULL || size<=0) return;
    int i;

    for(i=0;i<size;i++)
        free(tgt[i]);
        
    free(tgt);
}
