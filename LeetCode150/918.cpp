#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 918 on leetcode - Maximum Sum Circular Subarray
// https://leetcode.com/problems/maximum-sum-circular-subarray/

// The idea behind this problem is to find the maximum sum of subarray in a circular array.
// The maximum sum of subarray in a circular array will be the maximum of the maximum sum of subarray in a non circular array and the sum of all the elements in the array minus the minimum sum of subarray in a non circular array.

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int globalMax = nums[0];
        int globalMin = nums[0];
        int totalSum = 0;
        int currMin = 0;
        int currMax = 0;
        // finding the value of globalMin and globalMax in non circular array;
        for(int i = 0; i<nums.size(); i++)
        {
            // Either continuing the previous subarray or starting new one
            currMin = min(nums[i], nums[i] + currMin);
            globalMin =  min(globalMin, currMin);

            // Either continuing the previous subarray or starting new one 
            currMax = max(nums[i], nums[i] + currMax);
            globalMax = max(globalMax, currMax);


            totalSum += nums[i];
        }

        // if all the elements are zero in the array then globalMax will be value of max elements
        // and it will also be maximum for circular but if we try to find it using 
        // other method we will get zero which isn't possible so return 
        if(globalMax < 0) return globalMax;

        globalMax = max(globalMax, totalSum - globalMin);
        return globalMax;
        
    }
};
int main()
{
    vector<int> nums = nums = {1, -2, 3, -2};
    Solution solution;
    int ans = solution.maxSubarraySumCircular(nums);
    cout << ans << endl;
    return 0;
}