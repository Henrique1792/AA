#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
#include <vector>
#include <iterator>

class Person{
  protected:
    char ID;
    bool Married;
    std::vector <char> priority;
    std::vector<char>::iterator  priority_check;
    char Married_With;
    char gender;
 
  public:
    Person(char ID, char gender);
    ~Person();
    void set_marriage(bool value);
    void set_priorities(unsigned int people);
    char get_gender(); 
    std::vector <char> get_priorities();
    bool  get_mariage();
    char get_id();
};


#endif
