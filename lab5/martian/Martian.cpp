//
// Created by wojciechsalapatek on 27.03.18.
//

#include <iostream>
#include "Martian.h"

Martian::Martian() {
    liczbaMarsjan += 1;
}

Martian::~Martian(){
    if (liczbaMarsjan>0) liczbaMarsjan -= 1;
}



void Martian::attack() {
    if (liczbaMarsjan >=5) std::cout<<"Atakuje!!! jest nas: "<<liczbaMarsjan<<std::endl;
    else std::cout<<"Nie atakuje  bo jest nas: "<<liczbaMarsjan<<std::endl;
}