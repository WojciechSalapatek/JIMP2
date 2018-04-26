//
// Created by wojciechsalapatek on 21.04.18.
//

#ifndef JIMP_EXERCISES_SHAPE_H
#define JIMP_EXERCISES_SHAPE_H


class Shape {
public:
    virtual void Rysuj()const =0;
};

class Triangle : public Shape{
public:
    void Rysuj() const override ;
};

class Square : public Shape{
public:
    void Rysuj() const override ;
};

class Circle : public Shape{
public:
    void Rysuj() const override ;
};


#endif //JIMP_EXERCISES_SHAPE_H
