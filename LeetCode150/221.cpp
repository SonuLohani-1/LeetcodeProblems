#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int ROW;
    int COL;

    int helper(vector<vector<char>> &matrix, vector<vector<int>> &dp, int r, int c)
    {
        if (r >= ROW || c >= COL)
        {
            return 0;
        }
        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }

        int down = helper(matrix, dp, r + 1, c);
        int right = helper(matrix, dp, r, c + 1);
        int diag = helper(matrix, dp, r + 1, c + 1);

        dp[r][c] = 0;
        if (matrix[r][c] == '1')
        {
            dp[r][c] = 1 + min(down, min(right, diag));
        }
        return dp[r][c];
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        ROW = matrix.size();
        COL = matrix[0].size();

        vector<vector<int>> dp(ROW + 1, vector<int>(COL + 1, -1));
        int maxLen = 0;
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen*maxLen;
    }
};
int main()
{
    return 0;
}