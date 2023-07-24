#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 3Sum on leetcode
// https://leetcode.com/problems/3sum/

// The logic is to use three pointers, one from the start and one from the end and one from the current element
// and check if the sum of the three numbers is equal to zero or not
// if the sum is equal to zero then add the three numbers to the vector
// if the sum is greater than zero then decrement the end pointer
// if the sum is less than zero then increment the start pointer
// if the start pointer is greater than the end pointer then return the vector
// if the current element is equal to the previous element then increment the current element
// else return the vector

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int start = i + 1, end = n - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (start < end)
            {
                if (nums[i] + nums[start] + nums[end] == 0)
                {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while (start < end && nums[start] == nums[start - 1])
                        start++;
                    while (start < end && nums[end] == nums[end + 1])
                        end--;
                }
                else if (nums[i] + nums[start] + nums[end] > 0)
                    end--;
                else
                    start++;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}