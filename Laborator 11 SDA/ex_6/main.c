#include <stdio.h>
#include <stdlib.h>
#include "functii.h"

int main()
{
    sudoku_cell **sudoku;
    sudoku=(sudoku_cell**)malloc(9*sizeof(sudoku_cell*));
    for(unsigned int i=0; i<9; i++)
        sudoku[i] = (sudoku_cell*)malloc(9*sizeof(sudoku_cell));

    
    FILE *fp;
    fp = fopen("sudoku_init.txt", "rt");
    if(fp == NULL)
    {
        printf("Nu a fost gasit nici un sudoku.\n");
        exit(1);
    }
    
    for(unsigned int i=0; i<9; i++)
        for(unsigned int j=0; j<9; j++)
        {
            fscanf(fp, "%d", &(sudoku[i][j].value));
            if(sudoku[i][j].value!=0)
                sudoku[i][j].locked=1;
            else
                sudoku[i][j].locked=0;
        }

    if(rezolv_sudoku(sudoku))
        for(unsigned int i=0; i<9; i++)
        {
            printf("|");
            for(unsigned int j=0; j<9; j++)
            {
                printf("%d", sudoku[i][j].value);
                if( (j+1)%3==0 )
                    printf("|");
                else
                    printf(" ");
            }
            printf("\n");
            if( (i+1)%3==0 )
                printf("-------------------\n");
        }
    return 0;
}