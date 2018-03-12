//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

bool IsOutOfRange(int value);

int Factorial(int value) {
    if (IsOutOfRange(value)) return 0;
    int wynik = 1;
    if(value==0) return 1;
    if (value <0) {
        value = -value;
        if(value %2 !=0) wynik = -1;
    }
    for (int i=1;i<=value;i++) wynik *= i;
  return wynik;
}

bool IsOutOfRange(int value) { return value > 12 || value < -12; }
