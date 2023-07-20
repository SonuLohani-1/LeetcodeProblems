#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 134 on leetcode Gas Station
// https://leetcode.com/problems/gas-station/

// The detailed intuition for this problem is given is as follows:
// if the sum of gas is greater than the sum of cost then there exists a solution
// if there exists a solution then the starting point can be found by traversing the array and finding the point where the sum of gas is greater than the sum of cost
// if at any point sum becomes negative then we can start from the next point because there was something in tank when we started from the points in between and we can't reach the current point and if we start from 0 then still we definitely can't reach the current point.

// The time complexity of this solution is O(n) and space complexity is O(1)

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int sum = 0;
        int start = 0;
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0)
            {
                start = i + 1;
                sum = 0;
            }
        }
        if (total < 0)
        {
            return -1;
        }
        else
        {
            return start;
        }
    }
};
int main()
{
    return 0;
}