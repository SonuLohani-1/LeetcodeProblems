#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem Two Sum in LeetCode
// https://leetcode.com/problems/two-sum/

// This is my initial solution in O(n^2) time complexity
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// But we can do better than this in O(n) time complexity
class Solution
{
    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};
int main()
{
    return 0;
}