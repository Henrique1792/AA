#ifndef PERSON_H_
#define PERSON_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct PERSON_T{
  char *priorities;
  int gender;
  char marriedWith;
  
}PERSON;

PERSON *newPerson();
void freePerson();
int SetPriorities(PERSON *tgt);

#endif
