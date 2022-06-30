#include ../include/sub.h"

typedef struct
{
    int row;
    int col;
    double elem[2][2];
}matrix;

void init_matrix(matrix a)
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            a.elem[i][j] = 0.0;
        }
    }
}

matrix sum(matrix a, matrix b)
{
    matrix result;

    if(a.row==b.row && a.col==b.col)
    {
        int row = a.row, col = a.col;
        result.row = row;
        result.col = col;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                result.elem[i][j] = a.elem[i][j] + b.elem[i][j];
            }
        }
        return result;
    }
    else
    {
        result.row = 0;
        result.col = 0;
        return result;
    }
}

double inner_product(matrix a, matrix b)
{
    if(a.row==b.row && a.col==b.col)
    {
        int row = a.row, col = a.col;
        double result=0.0;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                result += a.elem[i][j] * b.elem[i][j];
            }
        }
        return result;
    }
    else
    {
        return 0;
    }
}

matrix product(matrix a, matrix b)
{
    matrix result;

    if(a.col==b.row)
    {
        int row = a.row, col = b.col;
        result.row = row;
        result.col = col;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                result.elem[i][j] = 0.0;
                for(int k=0; k<a.col; k++)
                {
                    result.elem[i][j] += a.elem[i][k] * b.elem[k][j];
                }
            }
        }
        return result;
    }
    else
    {
        result.row = 0;
        result.col = 0;
        return result;
    }
}

matrix transpose(matrix a)
{
    matrix result;
    int row = a.col, col = a.row;
    result.row = row;
    result.col = col;

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            result.elem[i][j] = a.elem[j][i];
        }
    }
    return result;
}

matrix inverse(matrix a)
{
    matrix result, sweep;

    if(a.row==a.col)
    {
        int N = a.row;
        result.row = N;
        result.col = N;
        sweep.row = N;
        sweep.col = N;

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                sweep.elem[i][j] = a.elem[i][j];
                result.elem[i][j] = (i==j) ? 1.0:0.0;
            }
        }
        
        for(int i=0; i<N; i++)
        {
            double cash_1, cash_2, abs = fabs(sweep.elem[i][i]);
            int abs_row = i;

            for(int j=i+1; j<N; j++)
            {
                if(fabs(sweep.elem[j][i])>abs)
                {
                    abs = fabs(sweep.elem[j][i]);
                    abs_row = j;
                }
            }

            if(abs < 1e-16)
            {
                result.row = 0;
                result.col = 0;
                return result;
            }
            else if(i != abs_row)
            {
                for(int k=0; k<N; k++)
                {
                    cash_1=sweep.elem[abs_row][k];
                    cash_2=result.elem[abs_row][k];
                    sweep.elem[abs_row][k] = sweep.elem[i][k];
                    result.elem[abs_row][k] = result.elem[i][k];
                    sweep.elem[i][k] = cash_1;
                    result.elem[i][k] = cash_2;
                }
            }

            cash_1 = 1/sweep.elem[i][i];
            for(int j=0; j<N; j++)
            {
                sweep.elem[i][j] *= cash_1;
                result.elem[i][j] *= cash_1;
            }

            for(int j=0; j<N; j++)
            {
                if(i!=j)
                {
                    cash_2 = sweep.elem[j][i];
                    for(int k=0; k<N; k++)
                    {
                        sweep.elem[j][k] -= cash_2*sweep.elem[i][k];
                        result.elem[j][k] -= cash_2*result.elem[i][k];
                    }
                }
                
            }
        }
        return result;
    }
    else{
        result.row = 0;
        result.col = 0;
        return result;
    }
}
