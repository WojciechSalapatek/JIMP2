//
// Created by wojciechsalapatek on 23.04.18.
//
#include <iostream>
#include <vector>
#include "Pesel.h"
using namespace academia;
using namespace std;

class CircleException{
    // Oznacza ze nie mozna wyrysowac kola
};

class BallException : public CircleException{
    // Oznacza ze nie mozna wyrysowac kuli
};

void drawBall() {
    throw BallException();
}


void CreatePesel(const string &pesel){
    Pesel p = Pesel(pesel);
}

int main(){
    std::vector<std::string> args = {"98012108919",};
    for(const auto &s : args) {
        try {
            CreatePesel(s); //ok
            CreatePesel("98012108910"); // bad checksum
            CreatePesel("1234567");  //bad length
            CreatePesel("1234567897877878787"); //bad length
            CreatePesel("12kl8790711"); //bad character
            CreatePesel("00000000000"); //ok
        } catch (InvalidPeselLength &e) {
            std::cerr << e.what() << std::endl;
        } catch (InvalidPeselCharacter &e) {
            std::cerr << e.what() << std::endl;
        } catch (InvalidPeselChecksum &e) {
            std::cerr << e.what() << std::endl;
        }
    }



    try{
        drawBall();
    }catch(BallException b){
        cerr << "Blad podczas rysowania kuli" << endl;
    }catch(CircleException a){
        cerr << "Blad podczas rysowania kola" << endl;
    }


    return 0;
}

