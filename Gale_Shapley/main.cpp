#include "person.h"



int main(int argc, char *argv[]){
  vector <char> priorities;
  vector <char>::iterator p_iterator;
  Person *test = new Person('A', 'M');
  test->set_priorities(5);
  priorities= test->get_priorities();

  delete(test);


  return 0;
}
