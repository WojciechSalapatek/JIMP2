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

typedef std::complex<double> complex;
namespace algebra {
    class Matrix {
    public:
        Matrix();

        ~Matrix();

        Matrix(int rows, int cols);

        Matrix(std::initializer_list<vector<complex>>);

        Matrix(string toParse);

        Matrix(const Matrix &other);

        Matrix & operator=(const Matrix &other);

        string Print() const;

        complex GetElement(int r, int c) const;

        void SetElement(int r, int c, complex value);

        Matrix Add(Matrix other) const;

        Matrix Sub(Matrix other) const;

        Matrix Mul(Matrix other) const;

        Matrix Pow(int to) const;

        pair<long unsigned int, long unsigned int> Size() const;


    private:
        complex **data;
        int l[5];
        int rows;
        int cols;
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
