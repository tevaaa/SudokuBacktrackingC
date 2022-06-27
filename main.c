#include "function.h"
#include <stdio.h> 
#include <stdlib.h>


int main(void)
{
    int **grid;
    int i;

    grid = (int **)malloc(9 * sizeof(int *)); // malloc number of rows
    i = 0;

    while(i < 9)        // malloc numbers of cells per row
    {
        *(grid+i) = (int *)malloc(9 * sizeof(int *));
        i++;
    }
    generate_sudoku(grid, 50);
    print_grid(grid);
    printf("Solving ...\n");
    solve(grid,0,0);
    print_grid(grid);
}