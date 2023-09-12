#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 188 on leetcode - buy and sell stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// This is the explanation for the recursion first we sell on ith day from start so we make profit p0 then we call the function from (i+1)th day to end to get the profit which will keep on repeating until the k = 1 for which we will try to get the maximum till end
class Solution {
private:
    int helper(vector<int>& prices, int i, int k, vector<vector<int>> &memo)
    {
        if(i == prices.size() || k == 0) return 0;
        if(memo[i][k] != -1) return memo[i][k];
        int ans = 0;
        int minm = prices[i];
        for(int j = i; j < prices.size(); j++)
        {
            if(prices[j] > minm)
                ans = max(ans, prices[j] - minm + helper(prices, j+1, k-1, memo));
            minm = min(minm, prices[j]);
        }
        return memo[i][k] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> memo(prices.size(), vector<int> (k+1, -1));
        return helper(prices, 0, k, memo);
    }
};



int main()
{
    return 0;
}