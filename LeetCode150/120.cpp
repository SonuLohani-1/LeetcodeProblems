#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // for this problem we have for ith level we have i + 1 choices to take
        int n = triangle.size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // dp[n-1] = triangle[n-1];
        // for(int i = n-2; i >= 0; i--)
        // {
        //     for(int j = 0; j < i; j++)
        //     {
        //         dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
        //     }
        // }
        // return dp[0][0];

        /* For the above row we need only the bottom row so we don't need O(n^2) space we just need O(n)*/

        vector<int> dp;
        dp = triangle[n-1];
        for(int i = n-2; i>=0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
int main()
{
    return 0;
}