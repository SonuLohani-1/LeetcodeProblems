#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem insert interval on leetcode
// https://leetcode.com/problems/insert-interval/

// This was my first approach
vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    if (intervals.size() == 0)
    {
        return {newInterval};
    }
    stack<vector<int>> st;
    int i = 0;
    bool flag = false;
    while (i < intervals.size())
    {
        if (flag)
            st.push(intervals[i]);
        else if (intervals[i][1] < newInterval[0])
        {
            st.push(intervals[i]);
        }
        else
        {
            // second element of interval i is greater than or equal to first element of newInterval
            if (intervals[i][0] > newInterval[1])
            {
                // in this case no merging happens
                st.push(newInterval);
                st.push(intervals[i]);
                flag = true;
            }
            else
            {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        i++;
    }
    if (!flag)
        st.push(newInterval);
    vector<vector<int>> ans(st.size());
    int ptr = st.size() - 1;
    while (!st.empty())
    {
        ans[ptr--] = st.top();
        st.pop();
    }
    return ans;
}

// This is a better approach

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < intervals.size())
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> ans = insert(intervals, newInterval);
    for (auto it : ans)
    {
        for (auto itr : it)
            cout << itr << " ";
        cout << endl;
    }
    return 0;
}