#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 219, Contains Duplicate II on leetcode.
// https://leetcode.com/problems/contains-duplicate-ii/

// The idea is to use a map to store the index of numbers that we have already seen.
// If we see a number that we have already seen, then we will check if the difference between the current index and the index of the number that we have already seen is less than or equal to k.
// If it is, then we will return true.

// time complexity: O(n)
// space complexity: O(n)

class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k)
        {
            map<int, int> m;
            for (int i = 0; i < nums.size(); i++)
            {
                if (m.find(nums[i]) != m.end())
                {
                    if (i - m[nums[i]] <= k)
                        return true;
                }
                m[nums[i]] = i;
            }
            return false;
        }
};

// A more efficient solution is to use a set.
// We will keep a window of size k.
// If we see a number that we have already seen, then we will return true.
// If the size of the set becomes greater than k, then we will remove the first element of the window from the set.
// time complexity: O(n)
// space complexity: O(k)

class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k)
        {
            set<int> s;
            for (int i = 0; i < nums.size(); i++)
            {
                if (s.find(nums[i]) != s.end())
                    return true;
                s.insert(nums[i]);
                if (s.size() > k)
                    s.erase(nums[i - k]);
            }
            return false;
        }
};
int main()
{
    return 0;
}