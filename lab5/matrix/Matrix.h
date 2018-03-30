//
// Created by wojciechsalapatek on 30.03.18.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <string>
#include <complex>
#include <vector>
using ::std::pair;

using std::string;
using std::vector;
namespace algebra {
    class Matrix {
    public:
        Matrix();

        Matrix(int rows, int cols);

        Matrix(std::initializer_list<vector<std::complex<double>>>);

        Matrix(string toParse);

        string Print() const;

        Matrix Add(Matrix other) const;

        Matrix Sub(Matrix other) const;

        Matrix Mul(Matrix other) const;

        Matrix Pow(int to) const;

        pair<int,int> Size();


    private:
        std::complex<double> **data;
        int l[5];
        int rows;
        int cols;
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
