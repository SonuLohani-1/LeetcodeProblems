#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 300 on leetcode - Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

// The solution is based on the concept of Dynamic Programming
// Time Complexity - O(n^2)
// Space Complexity - O(n)

class Solution {
// private:
//     int helper(vector<int>& nums, int last, int i)
//     {
//         if(i == nums.size()) return 0;
//         if(nums[i] <= last) return helper(nums, last, i+1);

//         // else we can either take the curr element or not
//         return max(1 + helper(nums, nums[i], i+1), helper(nums, last, i+1));
//     }
public:
    int lengthOfLIS(vector<int>& nums) {
        // This is the recursive solution
        // return helper(nums, INT_MIN, 0);
   
        vector<int> dp(nums.size(), 1);

        for(int i = nums.size()-2; i >= 0; i--)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] > nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// There exist a O(nlogn) solution for this problem
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int main()
{
    return 0;
}