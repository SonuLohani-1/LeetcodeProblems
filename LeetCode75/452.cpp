#include<bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>>& points) {
        // sort the points according to the first number and for each number go upto whereever it is possible to burst the balloons from a point in the current interval that is till where there is an overlap between the intervals.
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
        {
            return a[0] < b[0];
        });

        int ans = 1;
        int ptr = 1;
        vector<int> curr_interval = points[0];
        while(ptr < points.size())
        {
            if(curr_interval[1] < points[ptr][0])
            {
                ans++;
                curr_interval = points[ptr];
            }
            ptr++;
        }
        return ans;
    }
int main()
{
    vector<vector<int>> points = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};
    cout << findMinArrowShots(points) << endl;
    return 0;
}