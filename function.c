#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <time.h>

void print_grid(int **grid) // i : row, j : col
{
    int i, j;
    
    i = 0;

    printf("-------------------------------\n");
    while(i < 9)
    {
        
        j = 0;
        printf("|");
        while(j < 9)
        {

            printf(" %d ",*(*(grid+j)+i));
            if((j + 1) % 3 == 0)
            {
                printf("|");
            }
            j ++;
        }
        if((i + 1) % 3 == 0)
        {
           printf("\n-------------------------------");
        }
        printf("\n");
        i++;
    }
}

void generate_sudoku(int **grid, int n)
{
    // n -> number of iteration (digits to be placed)
    int j, k, r, x, y;
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
    srand(time(NULL));
    while(n > 0) // generate grid
    // take random cell if == 0 place random number 
    // but check if the number can be placed
    {
       
        x =  random(0, 8);
        y = random(0,8);
        r = random(1,9);
        if(is_valid(x,y,r,grid) == 1)
        {
            *(*(grid+x)+y) = r;
        }
        n--;
    }
}


int check_row(int y, int val, int **grid) // y row number
{
    int x, answ;

    x = 0;
    answ = 1;
    while(x < 9)
    {
        if( *(*(grid+x)+y) == val)
        {
            answ = 0;
        }
        x ++;
    }

    return answ; // 1 = valid, 0 = not valid
}

int check_col(int x, int val, int **grid)
{
    int y, answ;

    y = 0;
    answ = 1;

    while(y < 9)
    {
        if( *(*(grid+x)+y) == val)
            {
                answ = 0;
                y ++;
            }
        y ++;
    }
    return answ;
}

int check_box(int x, int y, int val, int **grid)
{
    int i, j, answ;
    i = x/3; // box index 0, 1 or 2 on x axis
    j = y/3; //                        y
    answ = 1;

    while(i < x/3+3)
    {
        while(j < y/3+3)
        {
            if(( *(*grid+i)+j) == val)
            {
                answ = 0;
            }
            j ++;
        }
        i++;
    }
    return answ;
}

int is_valid(int x, int y, int val, int **grid)
{
    int answ;

    answ = check_row(y, val, grid);
    if(answ == 1)
        answ = check_col(x, val, grid);
    if(answ == 1)
        answ = check_box(x, y, val, grid);
    return answ;
}

int random(int min, int max)
{
    int num;

    num = (rand() % (max - min +1 )) + min;
    return num;
}

int solve(int **grid, int x, int y)
{
    int val;

    if(x == 9 && y == 8) // if we are in the last cell
    {
        return 1;
    }
    
    if(x == 9) // go to next cell
    {
        y ++;
        x = 0;
    }

    if( *(*(grid + x) + y) > 0)
    {
        return solve(grid, x + 1, y);
    }
    
    val = 1;

    while(val <= 9)
    {
        if(is_valid(x, y, val, grid))
        {
            *(*(grid + x) + y) = val;

            if(solve(grid, x + 1, y))
            {
                return 1;
            }
        }
        *(*(grid + x) + y) = 0;
        val ++;
    }
    return 0;
}