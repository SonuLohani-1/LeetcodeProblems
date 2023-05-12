#include <bits/stdc++.h>
using namespace std;
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
int main()
{
        return 0;
}