//
// Created by wojciechsalapatek on 03.03.18.
//

#include "DoubleBasePalindromes.h"
#include <iostream>

using namespace std;

bool is_palindrome(int numb){
    string str = to_string(numb);
    int length = (int) str.length();
    for (int i=0;i<length/2;i++) if (str[i] != str[length-i-1]) return false;

    return true;


}

bool IsBinaryPalindrome(int value) {
    int number = value;
    int length = 0;
    string result = "";
    while (number != 0) {
        result += to_string(number%2);
        number = number/2;
    }
    length = result.length();
    for (int i=0;i<length/2;i++) if(result[i]!=result[length-i-1]) return false;
    return  true;
}

uint64_t DoubleBasePalindromes(int max_vaule_exculsive){
    uint64_t result = 0;
    if (max_vaule_exculsive < 0) return 0;
    for (int i=1;i<max_vaule_exculsive;i+=2) if(is_palindrome(i)) if(IsBinaryPalindrome(i)) result+=i;
    return result;
}