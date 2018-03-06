//
// Created by salawojc on 06.03.18.
//

#include "Array2D.h"

bool HasGoodDimensions(int n_rows, int n_columns);

int **NewArray2D(int n_rows, int n_columns){
    if (HasGoodDimensions(n_rows, n_columns)) return nullptr;
    int **array = new int*[n_rows];
    for (int i=0;i<n_rows;i++){
        array[i] = new int[n_columns];
    }
    return array;
}

void FillArray2D(int k_rows, int k_cols, int **to_fill){
    for (int i=0;i<k_rows;i++){
        for (int j = 0; j <k_cols ; ++j) {
            to_fill[i][j]=i*k_cols +j +1;
        }
    }
}

int **Array2D(int n_rows, int n_columns){
    if (HasGoodDimensions(n_rows, n_columns)) return nullptr;
    int **array = new int*[n_rows];
    int number =1;
    for (int i=0;i<n_rows;i++){
        array[i] = new int[n_columns];
        for (int j = 0; j < n_columns; j++) {
            array[i][j]=number;
            number++;
        }

    }
    return array;
}

bool HasGoodDimensions(int n_rows, int n_columns) { return n_columns <= 0 || n_rows <= 0; }

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i = 0; i <n_rows ; ++i) {
        delete [] array[i];
    }
    delete [] array;
}