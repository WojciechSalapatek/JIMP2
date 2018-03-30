//
// Created by wojciechsalapatek on 27.03.18.
//

#include "Martian.h"
#include <list>
#include <random>
#include <bits/streambuf_iterator.h>

int main(){
    int it =1;
    int choice;
    std::list<Martian> lista;
    while (it<100){
        for(auto i:lista) i.attack();
        choice = random() % 2;
        if (choice == 1) lista.push_back(Martian());
        else {
            if(std::find)
        }
        it++;
    }

    return 0;
}