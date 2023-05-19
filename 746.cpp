#include <bits/stdc++.h>
using namespace std;
/* 
// This is the recursive solution and doesn't pass all the testcases.
int minimizeCost(vector<int> &cost, int i)
{
    if (i >= cost.size())
        return 0;
    return cost[i] + min(minimizeCost(cost, i + 1), minimizeCost(cost, i + 2));
}

int minCostClimbingStairs(vector<int> &cost)
{
        return min(minimizeCost(cost, 0), minimizeCost(cost, 1));
}
*/

/*
// This is the dp solution using memoization and this passes all the test cases
    int minimizeCost(vector<int> &cost, int i, vector<int>& dp)
    {
    if (i >= cost.size())
        return 0;
    if(dp[i] != 0) return dp[i];
    return dp[i] = cost[i] + min(minimizeCost(cost, i + 1, dp), minimizeCost    (cost, i + 2, dp));
    }   

int minCostClimbingStairs(vector<int> &cost)
{
        vector<int> dp(cost.size(), 0);
        return min(minimizeCost(cost, 0, dp), minimizeCost(cost, 1, dp));
}
*/


// This is the dp solution
int minCostClimbingStairs(vector<int> &cost)
{
   // here the main question we are asking is what will be the minimum cost when starting from a particular point
   // The obvious answer for this is when we start from n-2th step the cost will cost[n-1] only so we need to keep this in mind;
   
}
int main()
{
        return 0;
}