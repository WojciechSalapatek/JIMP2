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

    Matrix::Matrix(std::initializer_list<vector<complex>> elements) {
       int  it = 0;
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
        cols = itc;
    }

    Matrix::~Matrix() {
        for (int i = 0; i < rows; ++i) delete [] data[i];
        delete [] data;
    }

    Matrix::Matrix(const Matrix &other) {
        this->rows = other.rows;
        this->cols = other.cols;
        data = new complex *[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new complex[cols];
            std::copy(other.data[i],other.data[i] +cols, data[i]);
        }
    }

    Matrix& Matrix::operator=(const Matrix &other) {
        for (int i = 0; i < rows; ++i) delete [] data[i];
        delete [] data;
        this->rows = other.rows;
        this->cols = other.cols;
        data = new complex *[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new complex[cols];
            std::copy(other.data[i],other.data[i] +cols, data[i]);
        }
    }

    pair<long unsigned int, long unsigned int> Matrix::Size() const{
        return {rows, cols};
    }

    string Matrix::Print() const {
        string result ="[";
        string val;
        for (int i=0; i< rows; i++){
            for (int j=0; j<cols; j++) {
                val = std::to_string(data[i][j].real());
                val.erase(val.find_last_not_of('0') + 1, string::npos);
                val.erase(val.find_last_not_of('.') + 1, string::npos);
                result += val;
                val = std::to_string(data[i][j].imag());
                val.erase(val.find_last_not_of('0') + 1, string::npos);
                val.erase(val.find_last_not_of('.') + 1, string::npos);
                result += "i" + val;
                if(j < cols-1) result += ", ";
                else result += "; ";
            }
        }
        result = result.substr(0,result.length()-2);
        result += "]";
        return result;
    }

    complex Matrix::GetElement(int r, int c) const{
        return data[r][c];
    }

    void Matrix::SetElement(int r, int c, complex value) {
        data[r][c] = value;
    }

    Matrix Matrix::Add(Matrix other) const{
        Matrix result = Matrix(rows, cols);
        if(Size() != other.Size()) std::cout<<"złe wymiary"<<std::endl;
        else{
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.SetElement(i,j, data[i][j] + other.GetElement(i,j));
            }
        }
        }
        return  result;
    }

    Matrix Matrix::Sub(Matrix other) const {
        Matrix result = Matrix(rows, cols);
        if(Size() != other.Size()) std::cout<<"złe wymiary"<<std::endl;
        else{
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.SetElement(i,j, data[i][j] - other.GetElement(i,j));
                }
            }
        }
        return  result;
    }

    Matrix Matrix::Mul(Matrix other) const {
        complex value = 0.;
        if(cols != other.rows) return Matrix(0,0);
        else{
            Matrix result = Matrix(rows, other.cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < other.cols; ++j) {
                    for (int k = 0; k < cols; ++k) {
                        value += data[i][k] * other.GetElement(k,j);
                    }
                    result.SetElement(i,j, value);
                    value = 0.;
                }
            }
            return  result;
        }
    }

    Matrix Matrix::Pow(int to) const {
        if(to == 0) {
            Matrix result = Matrix(rows, cols);
            for (int i = 0; i < rows; ++i) {
                result.SetElement(i, i, 1.);
            }
            return result;
        }
        if(to == 1) return *this;
        Matrix result = *this;
        for (int i = 1; i < to; ++i) {
            result = result.Mul(*this);
        }
        return result;
    }
}