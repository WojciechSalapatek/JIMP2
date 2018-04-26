//
// Created by wojciechsalapatek on 21.04.18.
//
#include <iostream>
#include <cmath>
#include "Shape.h"
using std::cout;
using std::endl;

void Triangle::Rysuj() const {
    int height = 10;
    for (int i = 1; i <= height; ++i) {
        for (int j = height-i-1; j >=0; j--) cout<<" ";
        for (int k = 1; k <= 2*i-1; ++k)cout<<"+";
        cout<<endl;
    }
}

void Square::Rysuj() const {
    int side = 10;
    for (int i = 0; i < side; ++i) cout<<"+";
    cout<<endl;
    for (int i = 0; i < side - 2; ++i) {
        for (int j = 0; j < side; ++j) cout<<"+";
        cout<<endl;
    }
    for (int i = 0; i < side; ++i) cout<<"+";
}

void Circle::Rysuj() const {
    int radius = 5;
    for (int i = 0; i < 2*radius+1; ++i) {
        for (int j = 0; j < 2*radius+1; ++j) {
            if (sqrt( pow((i-radius),2) + pow((j-radius),2) <=pow(radius,2)+1)) cout<<"+";
            else cout<<" ";
        }
        cout<<endl;

    }

}
