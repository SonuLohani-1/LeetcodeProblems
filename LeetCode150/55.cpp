#include<bits/stdc++.h>
using namespace std;

// This is the solution for the jump game problem on leetcode
// https://leetcode.com/problems/jump-game/

// The logic behind the problem is that if we can reach the last index from ith index or not so it is a dp solution

class Solution
{
    public:
        bool canJump(vector<int> &nums)
        {
            int n = nums.size();
            vector<bool> dp(n, false);
            dp[n - 1] = true;
            for (int i = n - 2; i >= 0; i--)
            {
                for (int j = 1; j <= nums[i]; j++)
                {
                    if (dp[i + j] == true)
                    {
                        dp[i] = true;
                        break;
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