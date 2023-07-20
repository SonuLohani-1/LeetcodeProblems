#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem jump game II on leetcode
// https://leetcode.com/problems/jump-game-ii/

// The logic behind solution is for every index what is the minimum number of steps required to reach the last position
// So we will use dp for this problem
// dp[n-1] = 0;
// dp[i] = min(dp[i+j]) + 1 for j = 1 to nums[i]

class Solution
{
    public:
        int jump(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n, INT_MAX);
            dp[n - 1] = 0;
            for (int i = n - 2; i >= 0; i--)
            {
                for (int j = 1; j <= nums[i]; j++)
                {
                    if (i + j < n)
                    {
                        dp[i] = min(dp[i], dp[i + j] + 1);
                    }
                }
            }
            return dp[0];
        }
};
int main()
{
    return 0;
}