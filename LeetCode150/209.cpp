#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem Minimum size subarray sum on leetcode
// https://leetcode.com/problems/minimum-size-subarray-sum/

// The intution behind this problem is that we can use sliding window to solve this problem
// We will use two pointers i and j to keep track of the window

// Time complexity O(n)
// Space complexity O(1)

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0, sum = 0, res = INT_MAX;
        while (j < nums.size())
        {
            sum += nums[j];
            while (sum >= target)
            {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
int main()
{
    return 0;
}