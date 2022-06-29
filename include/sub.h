#ifndef SUB_H
#define SUB_H

typedef struct
{
    int row;
    int col;
    double elem[2][2];
}matrix;

void init_matrix(matrix a);
matrix sum(matrix, matrix);
double inner_product(matrix, matrix);
matrix product(matrix, matrix);
matrix transpose(matrix);
matrix inverse(matrix);

#endif