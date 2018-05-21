
#include <iostream>

using namespace std;

class plaska_figura {
public:
    virtual float pole(){return 0;}
    virtual void info();
    virtual float obwod(){return 0;};
    virtual void piszP();
    plaska_figura(){};
};

void plaska_figura::info(){cout<<"Plaska figura. "<<endl;}
void plaska_figura::piszP(){info(); cout<<"Pole: "<<pole()<<endl<<"Obwod: "<<obwod()<<endl<<endl;}

class prostokat : public plaska_figura{
private:
    float a,b;
public:
    virtual void info() override ;
    virtual float pole()override {return a*b;}
    virtual float obwod() override {return 2*(a+b);}
    prostokat(float aa, float ab){a=aa; b=ab;};
};
void prostokat::info(){cout<<"Prostokat o bokach: "<<a<<" i "<<b<<". "<<endl;}


class kwadrat:public plaska_figura{
public:
    float a;

    virtual void info() override ;
    virtual float pole() override {return a*a;}
    virtual float obwod() override {return 4*a;}
    kwadrat(float aa){a=aa;};
};
void kwadrat::info(){cout<<"Kwadrat o boku: "<<a<<". "<<endl;}

class figura_przestrzenna:public plaska_figura{
public:
    virtual float objetosc(){return 0;}
    virtual void info() override;
    virtual float pole() override{ return 0;}
    void piszP() override {info(); cout<<"Pole: "<<pole()<<endl<<"Objetosc: "<<objetosc()<<endl<<endl;}

};

void figura_przestrzenna::info() {
    cout<<"Figura przesrzenna"<<endl;

}

class dana{
public:
    virtual void wypisz();
    virtual void wczytaj();
    virtual bool isvalid();
    virtual float get();
    dana();
    dana(const dana &aDana);

private:
    string msg;

};

float dana::get() {
    return 0;
}

void dana::wypisz() {

}

void dana::wczytaj() {

}

bool dana::isvalid() {
    return false;
}

dana::dana() {

}

dana::dana(const dana &aDana) {

}

class bok : public dana {
public:
    virtual void wypisz() override ;
    virtual void wczytaj() override ;
    virtual bool isvalid() override ;
    virtual float get() override ;
    bok(float l);
    bok(const bok &b);

private:
    float length;
};

void bok::wypisz() {
    cout<<"Bok ma długość: "<<length<<endl;
}

void bok::wczytaj() {
    cout<<"Podaj bok"<<endl;
    cin>>length;
}

bool bok::isvalid() {
    return (length>=0);
}

float bok::get() {
    return length;
}

bok::bok(float l) {
    length = l;
}

bok::bok(const bok &b) {
    length = b.length;
}

int main()
{
    plaska_figura T1;
    prostokat T(2,4);
    kwadrat K(5);
    figura_przestrzenna O1;

    K.piszP();
    T.piszP();
    T1.piszP();
    O1.piszP();
    bok b(-2);
    bok c(b);
    if(b.isvalid()) cout<<"Jest ok"<<endl;
    else cout<<"nie jest ok"<<endl;
    b.wczytaj();
    return 0;
}