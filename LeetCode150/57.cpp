#include <bits/stdc++.h>
using namespace std;
//This problem I think can be solved using the stack data type;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> &newInterval)
{
    if(intervals.size() == 0)
    {
        return {newInterval};
    }
    stack<vector<int>> st;
    int i = 0;
    bool flag = false;
    while(i < intervals.size())
    {
        if(flag)
            st.push(intervals[i]);
        else if(intervals[i][1] < newInterval[0])
        {
            st.push(intervals[i]); 
        }
        else
        {
            // second element of interval i is greater than or equal to first element of newInterval
           if(intervals[i][0] > newInterval[1])
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
    if(!flag)
        st.push(newInterval);
    vector<vector<int>> ans(st.size());
    int ptr = st.size()-1;
    while(!st.empty())
    {
        ans[ptr--] = st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {};
    vector<int> newInterval = {4, 8};
    vector<vector<int>> ans = insert(intervals, newInterval);
    for(auto it : ans)
    {
        for(auto itr : it)
            cout << itr << " ";
        cout << endl;
    }
    return 0;
}