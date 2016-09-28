#ifndef TABLE_H_
#define TABLE_H_

#define SIZE_RESTRICTION 2

#include <iostream>
#include <vector>



using namespace std;



/*
 * remember: 
 * x<y - ALWAYS
 *
 * */
typedef struct Restriction{
  int x1, y1, x2, y2;
}Restriction;

Restriction *create_Restriction();
void free_restriction(Restriction **tgt);
void print_rst(Restriction *tgt);

class Table{
  protected:
    int nRestrictions,size;
    vector <Restriction> *Restricted;
    int **board; 


  //iterators
    vector<Restriction>::iterator Restriction_check;

  public:
  //Constructor and Destructor
    Table(int size,int nRestrictions);
    ~Table();

  //Setters
    void set_table();
    void set_restrictions();


  //Printers
  void print_table();
  void print_restrictions();
};



#endif
