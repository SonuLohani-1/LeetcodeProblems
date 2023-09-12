#include<bits/stdc++.h>
using namespace std;    
// This is the solution for the problem 123 on leetcode - buy and sell stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// we can decide to sell first stock from 0 to n-1 days
// if we sell on day i then we can get profit of price on that day minus minimum price of 0 to i-1 days
// then for second stock we want to get maximum profit from i + 1 to n-1;
// so it is like single stock problem only 
class Solution {
private:
    // helper function to get the maximum profit from i to jth day of selling a stock
    void helper1(vector<int>& prices, vector<int> &maxProfit_0_to_i)
    {
    
        int minm = prices[0];
        for(int j = 1; j < prices.size(); j++)
        {
            maxProfit_0_to_i[j] = max(maxProfit_0_to_i[j-1], prices[j] - minm);
            minm = min(minm, prices[j]);
        }
    }

    void helper2(vector<int>& prices, vector<int> &maxProfit_i_to_end)
    {
        int n = prices.size();
        int maxm = prices[n-1];
        for(int j = n-2; j >= 0; j--)
        {
            maxProfit_i_to_end[j] = max(maxProfit_i_to_end[j+1], maxm - prices[j]);
            maxm = max(maxm, prices[j]);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = (int) prices.size();
        vector<int> maxProfit_0_to_i(n, 0);
        vector<int> maxProfit_i_to_end(n, 0);
        int ans = 0;
        helper1(prices, maxProfit_0_to_i);
        helper2(prices, maxProfit_i_to_end);
        ans = maxProfit_i_to_end[0];
        for(int i = 1; i < n-1; i++)
        {
            ans = max(ans, maxProfit_0_to_i[i]+maxProfit_i_to_end[i+1]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}