#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void print_grid(int i, int j, int **grid) // i : row, j : col
{
    int j_;
    int i_;


    i_ = 0;
    while(i_ < i)
    {
        
        j_ = 0;
        printf("[");
        while(j_ < j)
        {
            printf("%d,",*(*(grid+j_)+i_));
            j_ ++;
        }
        i_++;
    }
}

void generate_sudoku(int **grid, int n)
{
    // n -> number of iteration (digits to be placed)
    int i, j, k;

    grid = (int **)malloc(9 * sizeof(int *));

    i = 0;

    while(i < 9)
    {
        *(grid+i) = (int *)malloc(9 * sizeof(int *));
        i++;
    }

    j = 0;
    k = 0;

    while(j < 9)
    {
        k = 0;
        while(k < 9)
        {
            *(*(grid+j)+k) = 0;
            k ++;
        }
        j ++;
    }

}

