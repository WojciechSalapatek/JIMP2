//
// Created by mwypych on 02.02.17.
//
#include <iostream>
#include "Palindrome.h"

using std::string;
using namespace std;

void menu(){
    int choice = 0;
    string str;
    cout<<"Wybierz co chcesz zrobić"<<endl<<"1 - sprawdź palindrom"<<endl<<"2 - wyjście"<<endl;
    while(choice != 1  && choice != 2) {
        cin>>choice;
        cout<<"ello"<<endl;
    }

    if(choice == 1) {
        cout<<"Podaj wyraz"<<endl;
        cin>>str;
        if(IsPalindrome(str)) cout<<"wyraz jest palindromem"<<endl;
        else cout<<"wyraz nie jest palindromem"<<endl;
    }
}
bool IsPalindrome(string str){
    int length = (int) str.length();
    for (int i=0;i<length/2;i++) if (str[i] != str[length-i-1]) return false;

    return true;


}
