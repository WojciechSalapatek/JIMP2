//
// Created by wojciechsalapatek on 26.04.18.
//

#include <vector>
#include <iostream>
#include "Iterable.h"

using namespace utility;

int main(){
    std::vector<int> v {1,2,3,4};
    std::vector<string> b {"a", "b", "c", "d"};
    std::vector<string> c {};
    c.begin().operator*() == c.end().operator*();
    c.end().operator*();

    return 0;
}