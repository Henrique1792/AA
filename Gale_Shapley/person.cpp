#include "person.h"
#include <iostream>


//classes constructors
Person::Person(char ID){
  this->ID=ID;
  this->set_marriage(false);
};


//class destructor
Person::~Person(){};

//set marriage
void Person::set_marriage(bool value){
  this->Married=value;
};

//getters
bool Person::get_mariage(){
  return this->Married;
};

char Person::get_id(){
  return this->ID;
};


Man::Man(char ID):Person(ID){}
