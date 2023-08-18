#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 53. Maximum Subarray in LeetCode using Kadane's algorithm
// https://leetcode.com/problems/maximum-subarray/

// This is the solution if 0 size subarray is allowed
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum;
    }
};

// This is the solution if 0 size subarray is not allowed
class Solution {
public:
    // This is the method using the Kadane's algorithm.
    // The idea behind this method is to keep a current sum which we will update after each step to be maximum of subarray till now or the current element ( this is because if the current element is maxium then the previous sum of elements(including current element) there is no point of keeping those elements)
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int max_sum = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
           curr_sum = max(curr_sum + nums[i], nums[i]);
           max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
    }
};

// This is the divide and conquer method
// The idea behind this method is to divide the array into two parts and find the maximum subarray in the left part, right part and the subarray which crosses the middle element.
// The maximum of these three will be the answer.

// This is the divide and conquer algorithm for solving this problem in O(n log n) time
// The space complexity will be O(log n) stack space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
    int maxSubArray(vector<int>& nums, int l, int h)
    {
        if(l > h) return INT_MIN;
        if(l == h) return nums[l];

        int m = (h - l)/2 + l;
        return max(maxSubArray(nums, l, m - 1),
        max(maxSubArray(nums, m+1, h), maxCrossSum(nums, l, m, h)));
    }

    int maxCrossSum(vector<int>& nums, int l, int m, int h)
    {
        int sum = 0;
        int left_sum = INT_MIN;
        for(int i = m; i >= l; i--)
        {
            sum += nums[i];
            if(sum > left_sum)
            {
                left_sum = sum;
            }
        }

        sum = 0;
        int right_sum = INT_MIN;
        for(int i = m; i <= h; i++)
        {
            sum += nums[i];
            if(sum > right_sum)
            {
                right_sum = sum;
            }
        }

        return max(left_sum+right_sum - nums[m] , max(left_sum, right_sum));
    }
};
int main()
{
    return 0;
}