#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 238 on leetcode Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self/

// The intuition for this problem is that we can use two arrays left and right to store the product of the elements to the left and right of the current element
// The time complexity of this solution is O(n) and space complexity is O(n)
class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for(int i = 1; i < n; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
            right[n - i - 1] = right[n - i] * nums[n - i];
        }
        vector<int> ans(n, 1);
        for(int i = 0; i < n; i++)
        {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }

};

// Also if you notice we don't need extra space to store the left and right arrays
// We can use the ans array to store the left array and then we can use a variable to store the right array
// The time complexity of this solution is O(n) and space complexity is O(1)

class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int right = 1;
        for(int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            ans[i] = ans[i] * right;
            right = right * nums[i];
        }
        return ans;
    }

};

int main()
{
    return 0;
}