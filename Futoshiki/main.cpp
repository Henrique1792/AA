#include <iostream>
#include <string.h>
using namespace std;



int main(int argc, char *argv[]){

  if(argc>1){
    if (!strcmp(argv[1],"-L"))
      cout<<"LOOK AHEAD SET UP\n";
    else if (!strcmp(argv[1],"-M"))
      cout<<"LOOK AHEAD AND MVR SET UP\n";
  }
  else
    cout<<"NO PARAMETER\n";
  
  





  return 0;
}
