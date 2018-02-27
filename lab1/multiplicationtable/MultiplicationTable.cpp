//
// Created by mwypych on 02.02.17.
//
#include <iostream>
#include "MultiplicationTable.h"
#include <iomanip>
using std::string;
using namespace std;

void PrintTable(int tab[][10]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cout<<setw(5)<<tab[i][j]<< " ";
        }
        cout<<endl;
    }
}

void MultiplicationTable(int tab[][10]) {
    for (int i=0;i<10;i++) tab[0][i]=i+1;
    for (int i=0;i<10;i++) tab[i][0]=i+1;
    for (int i=1;i<10;i++){
        for (int j=1;j<10;j++){
            tab[i][j]= tab[0][j]*tab[i][0];
        }
    }
    PrintTable(tab);
}

