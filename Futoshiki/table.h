#ifndef TABLE_H_
#define TABLE_H_

#define SIZE_RESTRICTION 2

#include <iostream>
#include <vector>



using namespace std;



/*
 * remember: 
 *
 *
 * */
typedef struct Restriction{
  int x1, y1, x2, y2;
}Restriction;

class Table{
  protected:
    int nRestrictions;
    vector <Restriction> *Restricted;
    vector< vector<int> > board;
    vector<Restriction>::iterator Restriction_check;

  public:
  //Constructor and Destructor
    Table(int size,int nRestrictions);
    ~Table();

  //Setters
    


};



#endif
