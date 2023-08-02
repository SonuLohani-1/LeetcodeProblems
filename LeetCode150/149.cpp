#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 149 on leetcode - max points on a line
// https://leetcode.com/problems/max-points-on-a-line/

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() < 3) return points.size();
        int max_points = 2;
        for (int i = 0; i < points.size() - 2; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < points.size() - 1; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];

                int a = y2 - y1;
                int b = x1 - x2;
                int c = x1 * y2 - x2 * y1;

                int curr = 2;

                for (int k = j + 1; k < points.size(); k++)
                {
                    int x3 = points[k][0], y3 = points[k][1];
                    if (a * x3 + b * y3 == c)
                    {
                        curr++;
                    }
                }
                max_points = max(max_points, curr);
            }
        }
        return max_points;
    }
};
int main()
{
    return 0;
}