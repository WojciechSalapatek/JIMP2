#include <iostream>
#include "MultiplicationTable.h"
int main() {
    int tab [][10] = {{0,1,2,3,4,5,6,7,8,9},{1},{2},{3},{4},{5},{6},{7},{8},{9}};
    std::cout << "multiplication table :"<<std::endl;
    MultiplicationTable(tab);
  return 0;
}
