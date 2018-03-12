//
// Created by wojciechsalapatek on 11.03.18.
//

#include "XorCypherBreaker.h"
#include <algorithm>

double TryToDecode(const vector<char> &cryptogram,const vector<string> &dictionary,
                   const vector<char> &code){
    int position = 0;
    string word = "";
    int foundWords = 0;
    double badWords = 0;

    for (char i : cryptogram) {
        if (i == (' '^(code[position%3]))){
            if (find(dictionary.begin(),dictionary.end(),word) != dictionary.end()) {
                foundWords++;
                word = "";
            }
            else {
                word = "";
                badWords++;
            }
        }
        else{
            word += (i^(code[position%3])) | 0x20;
        }
        position++;
    }
    return foundWords/badWords;
}

string XorCypherBreaker(const vector<char> &cryptogram,
                        int key_length,
                        const vector<string> &dictionary) {

    vector<char> code;
    bool  go = true;
    string result = "";
    int it = key_length -1;
    for (int i = 0; i < key_length; ++i) { code.push_back('a');

    }
    while(go) {
        if (TryToDecode(cryptogram, dictionary, code) > 1) {
            for (char i : code) result += i;
            return result;
        }
        else{
            it = key_length -1;
            code[it]++;
            while (it>0){
                if (code[it] > 122) {
                    code[it-1]++;
                    if(code[0] > 122) go = false;
                    code[it]= 97;
                }
                it--;
            }
        }
    }
    return "";
}