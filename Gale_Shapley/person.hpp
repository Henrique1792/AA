#ifndef _PERSON_HPP_
#define _PERSON_HPP_
#include <iostream>


class Person{
  private:
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

class Man: public Person{
  private:
    int times_purposing;

  public: 
  Man(char ID):public Person(ID);
  void set_TimesPurposing(int ntimes);
  int get_timesPurposing();
};

class Woman: public Person{
  private:
    char married_with;

  public:
    void setIdiot(char husband);
    char getIdiot();
};
#endif
