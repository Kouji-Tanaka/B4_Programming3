#include <stdio.h>
#include "../include/sub.h"

void prt_mat(matrix a);
void prt_sca(double a);

int main(void)
{
    matrix x, y, A, B;
    
    init_matrix(x);
    init_matrix(y);
    init_matrix(A);
    init_matrix(B);

    x.row=2, x.col=1, x.elem[0][0]=5, x.elem[1][0]=7;
    y.row=2, y.col=1, y.elem[0][0]=2, y.elem[1][0]=3;
    A.row=2, A.col=2, A.elem[0][0]=1, A.elem[1][0]=4, A.elem[0][1]=3, A.elem[1][1]=2;
    B.row=2, B.col=2, B.elem[0][0]=2, B.elem[1][0]=3, B.elem[0][1]=1, B.elem[1][1]=2;

    
    printf("(1)");
    prt_mat(sum(x, y));
    printf("(2)");
    prt_sca(inner_product(x, y));
    printf("(3)");
    prt_mat(product(transpose(x), y));
    printf("(4)");
    prt_mat(product(A, x));
    printf("(5)");
    prt_mat(product(A, B));
    printf("(6)");
    prt_mat(product(B, A));
    printf("(7)");
    prt_mat(inverse(B));
    printf("(8)");
    prt_mat(transpose(product(A, B)));

    return 0;
}

void prt_mat(matrix a)
{
    if(a.row!=0)
    {
        for(int i=0; i<a.row; i++)
        {
            for(int j=0; j<a.col; j++)
            {
                printf("\t%f", a.elem[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("Error\n\n");
    }
}

void prt_sca(double a)
{
    if(a)
    {
        printf("\t%f\n\n", a);
    }
    else
    {
        printf("Error\n\n");
    }
}