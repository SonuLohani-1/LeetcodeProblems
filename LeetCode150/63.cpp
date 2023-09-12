#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 63 on leetcode - Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

// this is the space optimized dp solution for other solution check submissions on leetcode.
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // This is the true dp solution we can arrive at current square either from top or from the right so number of ways to reach the current square = no. of ways to reach top square + no. of ways to reach right square; the first rows and cols should be equal to 1

        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[r-1][c-1]) return 0;
        
        //vector<vector<int>> dp(r, vector<int>(c, 0));
        // dp[0][0] = 1;
        // doing the space optimization we only need a row so it can be done in O(n) time instead of O(n^2)

        vector<int> prev_row(c, 0);
        prev_row[0] = 1;
        
        for(int i = 0; i < r; i++)
        {
            vector<int> curr(c, 0);
            for(int j = 0; j < c; j++)
            {
                if(i == 0 && j == 0) curr[j] = 1;
                if(obstacleGrid[i][j] == 1) continue;
                if(i-1 >= 0) curr[j] += prev_row[j];
                if(j-1 >= 0) curr[j] += curr[j-1];
            }
            prev_row = curr;
        }

        return prev_row[c-1];
    }
};
int main()
{
    return 0;
}