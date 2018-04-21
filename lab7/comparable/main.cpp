//
// Created by wojciechsalapatek on 16.04.18.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include "Comparable.h"

int main(){
    ByFirstNameAscending less = ByFirstNameAscending();
    std::vector<Student> tosort= {
            Student {"1","Marek","Aureliusz","filozofia",StudyYear {3}},
            Student {"2","Albert","Einstein","muzyka",StudyYear{1}},
            Student {"3","Niels","Bohr","fizyka",StudyYear{1}},
            Student {"4","Ada","Lovelace","informatyka",StudyYear {4}},
            Student {"5", "Maria","Gopert-Mayer","fizyka",StudyYear {3}}};
    std::sort(tosort.begin(), tosort.end(), less);
    for (auto i: tosort){
        std::cout<<i.FirstName()<<" "<<i.LastName()<<" "<<i.Program()<<std::endl;
    }
}