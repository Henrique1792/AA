#include "person.h"

//class constructors
Person::Person(char ID, char gender){
  this->ID=ID;
  this->set_marriage(false);
  this->gender=gender;
}


//class destructor
Person::~Person(){}

//setters
void Person::set_marriage(bool value){
  this->Married=value;
}

void Person::set_purposes(int p){
  this->purposes=p;
}

void Person::set_priorities(unsigned int people){
  char reading;
  for (this->priority_check=this->priority.begin();
       this->priority.size()<people;
       this->priority_check++){
         cin>>reading;
         if(reading != '\n') this->priority.push_back(reading);
  }
  this->priority_check=this->priority.begin();
}
vector<char> Person::get_priorities(){
  return this->priority;
}

//getters
bool Person::get_mariage(){
  return this->Married;
}

char Person::get_id(){
  return this->ID;
}
char Person::get_gender(){
  return this->gender;
}

int Person::purposes_made(){
  return this->purposes;
}
