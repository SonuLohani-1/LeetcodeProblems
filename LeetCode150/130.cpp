// This is the surrounded regions problem solution
/*
This is the math part of the (i, j) coordinates to singular linear coordinates I am using
Matrix is like this:
 0  1  2  3  4  5
 6  7  8  9 10 11
12 13 14 15 16 17

with 3 rows and 6 cols
for e.g if i = 2, j = 4, idx = i*cols - 1 + j + 1 = i*cols + j = 2*6 + 4 = 16
which is true because element in our matrix is nothing but the indices only.

To go back to i, j
i = idx/cols = 16/6 = 2
j = idx - i*cols = 16 - 2 * 6 = 4

This is the way I can avoid using the pair map
*/
#include <bits/stdc++.h>
using namespace std;
int m, n;
void dfs(vector<vector<char>> &board, unordered_map<int, bool> &NotSurrounded, int i, int j)
{
    if (i < 0 || j < 0 || i >= m || j >= n)
        return;

    if (board[i][j] == 'X')
        return;

    int idx = i * n + j;
    if(NotSurrounded.find(idx) != NotSurrounded.end()) return;
    NotSurrounded[idx] = true;
    // up element
    dfs(board, NotSurrounded, i - 1, j);
    // down element
    dfs(board, NotSurrounded, i + 1, j);
    // left element
    dfs(board, NotSurrounded, i, j - 1);
    // right element
    dfs(board, NotSurrounded, i, j + 1);
    return;
}
void solve(vector<vector<char>> &board)
{
    unordered_map<int, bool> NotSurrounded; // instead of pair I will use single coordinate system
    // starting from first row and keep on increasing the count until the last element so the size will be
    // 0 to m*n - 1
    m = board.size();
    n = board[0].size();
    for (int i = 0; i < m; i++) // traversing and storing the position of not surrounded region market with 'O';
    {
        if (board[i][0] == 'O')
        {
            // cheking both the left-most column and right-most column
            if (NotSurrounded.find(i * n) == NotSurrounded.end())
            {
                dfs(board, NotSurrounded, i, 0);
            }
        }
        if (board[i][n - 1] == 'O')
        {
            if (NotSurrounded.find(i * n + n - 1) == NotSurrounded.end())
            {
                dfs(board, NotSurrounded, i, n - 1);
            }
        }
    }

    // Doing the same thing with the 1st and last row
    for (int i = 0; i < n; i++) // traversing and storing the position of not surrounded region market with 'O';
    {
        if (board[0][i] == 'O')
        {
            // cheking both the left-most column and right-most column
            if (NotSurrounded.find(0 * n + i) == NotSurrounded.end())
            {
                dfs(board, NotSurrounded, 0, i);
            }
        }
        if (board[m - 1][i] == 'O')
        {
            if (NotSurrounded.find((m - 1) * n + i) == NotSurrounded.end())
            {
                dfs(board, NotSurrounded, m - 1, i);
            }
        }
    }
    // Now traverse all the elements and mark them 'X' if not found in NotSurrounded
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx = i * n + j;
            if (NotSurrounded.find(idx) != NotSurrounded.end())
            {
                board[i][j] = 'O';
            }
            else
                board[i][j] = 'X';
        }
    }
}

int main()
{

    vector<vector<char>> board = {{'X','O','X'},{'O','X','O'},{'X','O','X'}};
    solve(board);
    for (auto it : board)
    {
        for (auto it2 : it)
            cout << it2 << " ";
        cout << endl;
    }
    return 0;
}