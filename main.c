#include "function.h"

int main(void)
{
    int **grid; 
    generate_sudoku(grid, 5);

    int j_;
    int i_;
    int i = 9;
    int j = 9;

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