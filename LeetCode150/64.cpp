#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 300 on leetcode - Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

// The solution is based on the concept of Dynamic Programming
// Time Complexity - O(n^2)
// Space Complexity - O(n^2)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        // This is O(n^2) space dp solution
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        // last row and column should can filled easily

        // for row m-1
        // cost[m-1][n-1] = grid[m-1][n-1];
        for(int i = n-2; i >= 0; i--)
        {
            cost[m-1][i] = grid[m-1][i] + cost[m-1][i+1];
        }

        // for col n-1;
        for(int i = m-2; i >= 0; i--)
        {
            cost[i][n-1] = grid[i][n-1] + cost[i+1][n-1];
        }

        for(int i = m-2; i >= 0; i--)
        {
            for(int j = n-2; j >= 0; j--)
            {
                cost[i][j] = grid[i][j] + min(cost[i][j+1], cost[i+1][j]);
            }
        }
        return cost[0][0];
    }
};

// There 
int main()
{
    return 0;
}