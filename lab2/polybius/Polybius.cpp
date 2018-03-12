//
// Created by wojciechsalapatek on 05.03.18.
//

#include "Polybius.h"
#include <map>

using namespace std;

map<char, int> MakeMapToEncrypt() {
    char letter = 'a';
    map<char,int> table;
    for (int i=1;i<6;i++) {
        for (int j = 1; j < 6; j++) {
            table[letter] = i * 10 + j;
            if (letter=='i') letter++;
            letter++;
        }
        table['j'] = 24;
    }
    return table;
}

string PolybiusCrypt(string message){
    string result = "";
    map<char, int> table = MakeMapToEncrypt();
    for (auto i :message){
        i = i | 0x20;
        if(i==' ') continue;
        result+= to_string(table[i]);
    }
    return result;
}

map<int, char> MakeMapToDecrypt() {
    char letter = 'a';
    map<int,char> table;
    for (int i=1;i<6;i++) {
        for (int j = 1; j < 6; j++) {
            table[i * 10 + j] = letter;
            if (letter == 'i') letter++;
            letter++;
        }

    }
    return table;
}



string PolybiusDecrypt(string crypted){
    string result = "";
    if(crypted=="") return "";
    int j=0;
    map<int, char> table = MakeMapToDecrypt();
    for (int i=0; i<crypted.length()-1;i+=2){
        j = crypted[i] - '0';
        j = j*10 + crypted[i+1] - '0';
        result+=table[j];
    }
    return result;

}