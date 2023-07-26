#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 128 on Leetcode - Longest Consecutive Sequence.
// https://leetcode.com/problems/longest-consecutive-sequence/

// The efficient solution is to use a set.
// We will insert all the numbers in the set.
// Then we will iterate over the set.
// If the current number is the first number of a sequence, then we will check if the next number is present in the set.
// If it is, then we will increment the length of the sequence.
// If the current number is not the first number of a sequence, then we will continue.
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
    public:
        int longestConsecutive(vector<int>& nums)
        {
            set<int> s;
            for (int i = 0; i < nums.size(); i++)
                s.insert(nums[i]);
            int ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (s.find(nums[i] - 1) == s.end())
                {
                    int j = nums[i];
                    while (s.find(j) != s.end())
                        j++;
                    ans = max(ans, j - nums[i]);
                }
            }
            return ans;
        }
};
int main()
{
    return 0;
}