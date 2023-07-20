#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem rotate array on leetcode
// https://leetcode.com/problems/rotate-array/

// This is the less optimized solution
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> last_K;
        for (int j = n - k; j < n; j++)
        {
            last_K.push_back(nums[j]);
        }
        for (int j = n - 1; j >= k; j--)
        {
            nums[j] = nums[j - k];
        }
        for (int i = 0; i < k; i++)
        {
            nums[i] = last_K[i];
        }
    }
};

// This is the optimized solution
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
int main()
{
    return 0;
}