//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    int wynik = 1;
    if(value==0) return 1;
    else if (value > 12 || value < -12) return 0;
    else if (value <0) {
        value = -value;
        if(value %2 !=0) wynik = -1;
    }
    for (int i=1;i<=value;i++) wynik *= i;
  return wynik;
}
