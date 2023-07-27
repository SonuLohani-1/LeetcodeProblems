#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem Minimum number of arrows to burst balloons on leetcode
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// This was my first approach
// The time complexity = O(nlogn + n) = O(nlogn)
// Space complexity = O(1);
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        // sort the points according to the first number and for each number go upto whereever it is possible to burst the balloons from a point in the current interval that is till where there is an overlap between the intervals.
        if (points.size() == 0 || points.size() == 1)
            return points.size();
        int count = 0;
        int min_end = INT_MAX;
        sort(points.begin(), points.end());
        for (auto p : points)
        {
            if (p[0] > min_end)
            {
                count++;
                min_end = p[1];
            }
            else
                min_end = min(min_end, p[1]);
        }
        return count + 1;
    }
};


// This is a better approach
// The idea is to sort the intervals according to the second number and then for each interval check if the first number of the current interval is greater than the second number of the previous interval then we need to burst the balloon at the second number of the current interval and increment the count.
// The time complexity = O(nlogn + n) = O(nlogn)
// Space complexity = O(1);
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0 || points.size() == 1)
            return points.size();
        int count = 0;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int prev = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > prev)
            {
                count++;
                prev = points[i][1];
            }
        }
        return count + 1;
    }
};

int main()
{
    return 0;
}