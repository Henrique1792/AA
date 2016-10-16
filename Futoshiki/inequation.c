#include "inequation.h"



INEQUATION *create_inq(){
  INEQUATION *rt=(INEQUATION *)malloc(sizeof(INEQUATION));
  return rt==NULL ?  NULL : rt;
}

INEQUATION *copy_inq(INEQUATION *origin, int size){
    if(origin && size > 0){
        INEQUATION *copy = (INEQUATION *) malloc(size * sizeof(INEQUATION));

        int i = 0;
        for(i = 0; i < size; i++){
            copy[i].x1 = origin[i].x1;
            copy[i].y1 = origin[i].y1;
            copy[i].x2 = origin[i].x2;
            copy[i].y2 = origin[i].y2;
        }

        return copy;
    }
    return NULL;
}

int set_inq_values(INEQUATION *tgt, int x1, int x2, int y1, int y2, int size){
  if((x1>=size ||x1<0)||
    (x2>=size ||x2<0)||
    (y1>=size ||y1<0)||
    (y2>=size ||y2<0)||
    tgt==NULL) return FAIL;

  tgt->x1=x1;
  tgt->x2=x2;
  tgt->y1=y1;
  tgt->y2=x2;
  return SUCCESS;
}

void print_inq(INEQUATION tgt){
    printf("%d %d %d %d\n", tgt.x1, tgt.y1, tgt.x2, tgt.y2);
}

void free_inq(INEQUATION *tgt){
  if(tgt==NULL) return;
  free(tgt);
}
