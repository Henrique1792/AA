#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
class Person{
  protected:
    char ID;
    bool Married;
    vector <char> priority;
    vector<char>::iterator  priority_check;
    char Married_With;
    char gender;
 
  public:
   //constructor and destructor
    Person(char ID, char gender);
    ~Person();
   //setters
    void set_marriage(bool value);
    void set_priorities(unsigned int people);
   //getters
    char get_gender(); 
    vector <char> get_priorities();
    char get_id();
    bool  get_mariage();
};


#endif
