#include "function.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

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
    generate_sudoku(grid, 30);
    print_grid(grid);
    clock_t start, end;
    double cpu_time_used;
     
     start = clock();
     
     
    printf("Solving ...\n");
    if(solve(grid,0,0))
    {
        end = clock();
        cpu_time_used = ((double) (end - start));
        printf("Solution founded in %d ms", cpu_time_used);
        print_grid(grid); 
    }
       
    else
        printf("Unsolvable :(");
}