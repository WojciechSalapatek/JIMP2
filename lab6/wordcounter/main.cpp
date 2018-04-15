//
// Created by wojciechsalapatek on 14.04.18.
//

#include <fstream>
#include <iostream>
#include "WordCounter.h"
using namespace datastructures;
int main() {
    std::ifstream is("myfile.txt");
    if(!is) std::cout << "Nie można otworzyć pliku!" << std::endl;
    WordCounter wc;
    if (is) wc = WordCounter::FromInputStream(is);
    else return 1;
// w zmiennej ilość powinna znaleźć się ilość powtórzeń
// słowa "programowanie" w pliku "myfile.txt"
    int ilosc = wc["programowanie"];
    std::cout<<ilosc<<std::endl;
    return 0;
}