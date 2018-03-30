//
// Created by wojciechsalapatek on 30.03.18.
//

#include "Matrix.h"
#include <ostream>
#include <iostream>

typedef std::complex<double> complex;
using std::vector;


namespace algebra {
    Matrix::Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        data = new complex *[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new complex[cols];
        }
    }

    Matrix::Matrix(std::initializer_list<vector<complex>>) {
       /* int  it = 0;
        int  itc = 0;
        data = new complex *[elements.size()];
        for(auto i : elements){
            data[it] = new complex[i.size()];
            itc = 0;
            for(auto j: i) {
                data[it][itc] = j;
                itc++;
            }
            it++;
        }
        rows = it;
        cols = itc;*/
    }

    pair<int, int> Matrix::Size() {
        return {rows, cols};
    }

    string Matrix::Print() const {
        string result ="[";
        std::ostringstream converter;
        for (int i=0; i< rows; i++){
            for (int j=0; j<cols; j++) converter<<data[i][j];
            result += converter.str();
            converter.str("");
            result += ", ";
        }
        result = result.substr(0,result.length()-2);
        result += "]";
        std::cout<<result;
        return result;
    }

    Matrix Matrix::Add(Matrix other) const{

    }

    Matrix Matrix::Sub(Matrix other) const {

    }

    Matrix Matrix::Mul(Matrix other) const {

    }

    Matrix Matrix::Pow(int to) const {

    }
}