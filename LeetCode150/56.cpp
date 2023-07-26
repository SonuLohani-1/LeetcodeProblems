#include<bits/stdc++.h>
using namespace std;

// This is the soltuion of the problem 56, Merge Intervals on leetcode.
// https://leetcode.com/problems/merge-intervals/

// The idea is to sort the intervals according to their starting time.
// Then we will iterate over the intervals.
// If the current interval's starting time is greater than the ending time of the last interval in the answer, then we will push the current interval in the answer.
// Else we will merge the current interval with the last interval in the answer.

// time complexity: O(nlogn)
// space complexity: O(1)

class Solution
{
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals)
        {
            sort(intervals.begin(), intervals.end());
            vector<vector<int>> ans;
            ans.push_back(intervals[0]);
            for (int i = 1; i < intervals.size(); i++)
            {
                if (intervals[i][0] > ans[ans.size() - 1][1])
                    ans.push_back(intervals[i]);
                else
                    ans[ans.size() - 1][1] = max(ans[ans.size() - 1][1], intervals[i][1]);
            }
            return ans;
        }
};


int main()
{
    return 0;
}