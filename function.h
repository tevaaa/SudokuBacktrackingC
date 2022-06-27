

void generate_sudoku(int **gird, int n);
void print_grid(int **grid);

int check_row(int y, int val, int **grid);
int check_col(int x, int val, int **grid);
int check_box(int x, int y, int val, int **grid);
int is_valid(int x, int y, int val, int **grid);

int random(int min, int max);

int solve(int **grid, int x, int y);