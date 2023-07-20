#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem Trappling Rain Water on leetcode
// https://leetcode.com/problems/trapping-rain-water/

// The logic behind the problem is that we will keep track of the maximum height on the left and right of the current element and then we will take the minimum of the two and subtract the height of the current element from it and add it to the answer.
class Solution
{
    public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int maxLeft = 0;
        int maxRight = 0;
        for (int i = 0; i < n; i++)
        {
            maxLeft = max(maxLeft, height[i]);
            left[i] = maxLeft;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            maxRight = max(maxRight, height[i]);
            right[i] = maxRight;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};

// This is the optimized solution
class Solution
{
    public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int ans = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxLeft)
                {
                    maxLeft = height[left];
                }
                else
                {
                    ans += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= maxRight)
                {
                    maxRight = height[right];
                }
                else
                {
                    ans += maxRight - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}