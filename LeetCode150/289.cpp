#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem Game of Life on Leetcode
// https://leetcode.com/problems/game-of-life/

// We can solve this problem in O(1) space by using the fact that
// the numbers are given in int
// there are these scenarios possible
// i) a cell is alive and it remains alive
// ii) a cell is dead and it remains dead
// iii) a cell is alive and it becomes dead
// iv) a cell is dead and it becomes alive
// I will represent a cell which does not change its states as 0 or 1
// and a cell becomes dead that by -1 and a cell becomes alive by 2

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int count = 0;
                for (int delx = 0; delx < 8; delx++)
                {
                    int newx = i + dx[delx];
                    int newy = j + dy[delx];

                    if (newx >= 0 && newx < rows && newy >= 0 && newy < cols)
                    {
                        if (board[newx][newy] == 1 || board[newx][newy] == -1)
                        {
                            count++;
                        }
                    }
                }
                // die due to underpopulation
                if (count < 2 && board[i][j] == 1)
                {
                    board[i][j] = -1;
                }

                // die due to overpopulation
                else if (count > 3 && board[i][j] == 1)
                {
                    board[i][j] = -1;
                }

                // become alive due to reproduction
                else if (count == 3 && board[i][j] == 0)
                {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == -1)
                {
                    board[i][j] = 0;
                }
                else if (board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
            }
        }
    }
};
int main()
{

    return 0;
}