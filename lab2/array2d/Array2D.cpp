//
// Created by wojciechsalapatek on 05.03.18.
//

#include "Array2D.h"

void FillArray2D(int k_rows,int k_cols, int *const *to_fill);

int **NewArray2D(int n_rows, int n_columns);

int **Array2D(int n_rows, int n_columns) {
    int number=1;
    if (n_rows <= 0 || n_columns <=0) return nullptr;
    int **a;
    a = NewArray2D(n_rows, n_columns);
    FillArray2D(n_rows,n_columns,a);
    return a;

}

int **NewArray2D(int n_rows, int n_columns) {
    int **a = new int*[n_rows];
    for (int i=0; i < n_rows; i++){
        a[i]= new int[n_columns];
    }
    return a;
}

void FillArray2D(int k_rows,int k_cols, int *const *to_fill) {
    for (int i = 0; i < k_rows ; ++i) {
        for (int j = 0; j < k_cols; j++) {
            to_fill[i][j] = i * k_cols + j + 1;
        }
    }
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i=0;i<n_rows;i++){
        delete [] array[i];
        }
    delete []  array;
}