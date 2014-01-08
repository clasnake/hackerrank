#include <iostream>
using namespace std;

bool find(int grid[9][9], int& row, int& col)
{
    for (int i= 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!grid[i][j]) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool check(int grid[9][9], int row, int col, int n)
{
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == n) {
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == n) {
            return false;
        }
    }
    int x = row / 3 * 3;
    int y = col / 3 * 3;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (grid[i][j] == n) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int grid[9][9])
{
    int row, col;
    if (!find(grid, row, col)) {
        return true;
    }
    for (int x = 1; x <= 9; x++) {
        if (check(grid, row, col, x)) {
            grid[row][col] = x;
            if (sudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

void print(int grid[9][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int T;
    int grid[9][9];
    cin >> T;
    while (T--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> grid[i][j]; 
            }
        }
        sudoku(grid);
        print(grid);
    }
    return 0;
}
