//
// Created by mwypych on 02.02.17.
//
#include <iostream>
#include "ReverseString.h"
using std::string;

string reverse(std::string str) {

    int length = str.length();
    string result = str;
    for (int i=0;i<length;i++) {
        std::cout<<str[i]<<std::endl;
        result[length-i-1] = str[i];
    }
    std::cout<<result<<std::endl;
    return result;
}
