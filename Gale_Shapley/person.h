#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>


class Person{
    char ID;
    bool Married;
    char *priority; 

  public:
    Person(char ID);
    ~Person();
    void set_marriage(bool value);
    void set_priorities();
    char *get_priorities();
    bool  get_mariage();
    char get_id();
};

class Man : public Person{

  public:
    Man(char ID);
    ~Man();


};


#endif
