#include <stdio.h>
#include <stdlib.h>
#include "structuri.h"

int is_in_col(sudoku_cell** sudoku, int j, int k)
{
    for(unsigned int i=0;i<9;i++)
        if(sudoku[i][j].value==k)
            return 1;
    return 0;
}

int is_in_row(sudoku_cell** sudoku, int i, int k)
{
    for(unsigned int j=0;j<9;j++)
        if(sudoku[i][j].value==k)
                return 1;
    return 0;
}

int is_in_square(sudoku_cell** sudoku, int n, int m, int k)
{
    n=n-n%3;
    m=m-m%3;
    for(unsigned int i=n;i<n+3; i++)
        for(unsigned int j=m;j<m+3;j++)
            if(sudoku[i][j].value==k)
                return 1;
    return 0;  
}


int valid(sudoku_cell** sudoku, int i, int j, int k)
{
    if( !is_in_row(sudoku,i,k) && !is_in_col(sudoku,j,k) && (!is_in_square(sudoku,i,j,k)) )
        return 1;
    else 
        return 0;

}

int empty_cell(sudoku_cell** sudoku, int *i, int *j)
{
    for(*i=0;*i<9;(*i)++)
        for(*j=0;*j<9;(*j)++)
            if(sudoku[*i][*j].value==0)
                return 1;
    return 0;
}


int rezolv_sudoku(sudoku_cell** sudoku)
{
    int i=0,j=0;

    if(!empty_cell(sudoku,&i,&j))
        return 1;
    for(unsigned int k=1;k<=9;k++)
        {
            if(valid(sudoku, i, j, k))
            {
                sudoku[i][j].value=k;
                if(rezolv_sudoku(sudoku))
                    return 1;
                sudoku[i][j].value=0;
            }
        }
    return 0;
}