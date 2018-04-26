//
// Created by wojciechsalapatek on 21.04.18.
//

#include "Shape.h"
#include <list>
#include <iostream>
#include <memory>

using std::list;
using std::unique_ptr;

int main() {
    list<Shape*> aList;
    Triangle a = Triangle();
    Square b = Square();
    Circle c = Circle();
    aList.push_back(&a);
    aList.push_back(&b);
    aList.push_back(&c);
    for(auto i: aList) {
        i->Rysuj();
        std::cout<<std::endl;
        std::cout<<std::endl;
    }
    return 0;
}
