//
// Created by wojciechsalapatek on 10.03.18.
//

#include "GreatestProduct.h"
#include <cmath>
using namespace std;
int GetMin(const vector<int> &tmp);


int GreatestProduct(const std::vector<int> &numbers, int k){
    int min, result = 1;
    if (k>numbers.size()) return 0;
    vector<int> tmp;
    for (int i=0; i<k; i++) tmp.push_back(numbers[i]);
    min = GetMin(tmp);
    for (int i = k; i<numbers.size();i++){
        if (numbers[i]>tmp[min]) {
            tmp[min] = numbers[i];
            min = GetMin(tmp);
        }
    }
    for (auto i : tmp) result *= i;
    return result;
}

int GetMin(const vector<int> &tmp) {
    int  min = 0;
    for (int i=0;i<tmp.size(); i++) {
            if (tmp[i] < tmp[min]) min=i;
        }
    return min;
}