//
// Created by wojciechsalapatek on 05.03.18.
//

#include "Polybius.h"
#include <fstream>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc,  char** argv)
{
    string word;
    cout<<*argv[3]<<argv[2]<<endl;
    if (int(*argv[3]) == '1') {
        cout<<"coś"<<endl;
        ifstream input(argv[1]);
        ofstream output(argv[2],ios_base::in | ios_base::app);
        while(input >> word) {
            cout<<word;
            output<<PolybiusCrypt(word);
        }

    }
    return 0;
}