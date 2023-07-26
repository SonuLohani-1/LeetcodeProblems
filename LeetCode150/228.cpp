#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 228, Summary Ranges on leetcode.
// https://leetcode.com/problems/summary-ranges/

/*
vector<string> summaryRanges(vector<int> &nums)
{
    if(nums.size() == 0) return {};
    if(nums.size() == 1) return {to_string(nums[0])};
    int lower_bound = nums[0];
    int upper_bound;
    vector<string> ans;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] != nums[i-1]+1)
        {
            upper_bound = nums[i-1];
            if(lower_bound == upper_bound) ans.push_back(to_string(lower_bound));
            else ans.push_back(to_string(lower_bound) + "->" + to_string(upper_bound));
            lower_bound = nums[i];
        }
    }
    if(upper_bound != nums[nums.size()-1])
    {
        upper_bound = nums[nums.size()-1];
        if(upper_bound == lower_bound)
            ans.push_back(to_string(lower_bound));
        else
            ans.push_back(to_string(lower_bound) + "->" + to_string(upper_bound));
    }
    return ans;
}
*/

// Above one was my first solution a more elegant solution is below.
// We will keep track of the last number and the previous number.
// If the current number is not equal to the previous number + 1, then we will push the range in the answer.
// time complexity: O(n)
// space complexity: O(1)
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        // base Cases
        if (nums.size() == 0)
            return {};
        if (nums.size() == 1)
            return {to_string(nums[0])};

        int last = nums[0];
        int prev = nums[0];
        int curr;

        vector<string> ans;

        for (int i = 1; i < nums.size(); i++)
        {
            curr = nums[i];

            if (curr != prev + 1)
            {
                if (last == prev)
                {
                    ans.push_back(to_string(last));
                }
                else
                {
                    ans.push_back(to_string(last) + "->" + to_string(prev));
                }

                last = curr;
            }

            prev = curr;
        }

        if (last == prev)
        {
            ans.push_back(to_string(last));
        }
        else
        {
            ans.push_back(to_string(last) + "->" + to_string(prev));
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    Solution solution;
    vector<string> ranges = solution.summaryRanges(nums);
    for (auto it : ranges)
    {
        cout << it << endl;
    }
    return 0;
}