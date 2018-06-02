//
// Created by wojciechsalapatek on 22.05.18.
//

#include <memory>
#include <FactoryMethod.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace factoryMethod;

int main(){
    vector<int> v {1,2,3};
    unique_ptr<int> i = make_unique<int>(2);
    cout<<i.operator*()<<endl;
    cout<<factoryMethod::Value<unique_ptr<int>>(move(i))<<endl;
    cout<<factoryMethod::Value<__gnu_cxx::__normal_iterator<int*,vector<int>>>(v.begin())<<endl;
    Buffor buffor = Buffor();
    buffor.CheckLogger();
    return 0;
}
