#include<bits/stdc++.h>
using namespace std;
// This is the solution of problem 52 on leetcode - N-Queens II
// https://leetcode.com/problems/n-queens-ii/

// The idea is to use backtracking to find all the possible combinations
// The time complexity is O(2^n) and space complexity is O(n)

// This is the solution written by me
// both the solutions use the same logic but implemented little differently
class Solution {
private:
    void backtrack(int n, vector<vector<int>> &hasQueen, int &ans, int row)
    {
        if(row == n)
        {
            ans++;
            return;
        }

        for(int col = 0; col < n; col++)
        {   
                int r = row;
                int c = col;
                int c_r = col;

                bool flag = true;

                // checking for queen in all directions
                while(r>=0 || c>=0 || c_r < n)
                {
                    // we have to check left diagonal
                    if(r >= 0 && c >= 0 && hasQueen[r][c])
                    {
                        flag = false;
                        break;
                    }
                    //checking the right diagonal
                    if(r >= 0 && c_r < n && hasQueen[r][c_r])
                    {
                        flag = false;
                        break;
                    }

                    //checking the curr col
                    if(r >= 0 && hasQueen[r][col])
                    {
                        flag = false;
                        break;
                    }
                    r--;
                    c--;
                    c_r++;
   
                }

                if(flag)
                {
                    hasQueen[row][col] = 1;
                    backtrack(n, hasQueen, ans, row+1);
                    hasQueen[row][col] = 0;
                }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<int>> hasQueen(n, vector<int>(n, 0));
        int ans = 0;
        backtrack(n, hasQueen, ans, 0);
        return ans;
    }
};


class Solution2
{
    public:
    int ans = 0;
    bool isSafe(vector<string> &board, int row, int col)
    {
        int n = board.size();
        for (int i = 0; i < row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void solve(vector<string> &board, int row)
    {
        int n = board.size();
        if (row == n)
        {
            ans++;
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col))
            {
                board[row][col] = 'Q';
                solve(board, row + 1);
                board[row][col] = '.';
            }
        }
    }
};
int main()
{
    return 0;
}