#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem Best time to buy and sell stocks II on leetcode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// The logic for this solution is that we will add the profit whenever the price of the stock is greater than the previous price.

// let's say we have minimum price on jth day and we are selling on ith day where price is maximum 
// Also let's assume some day k in the between has some price in the middle

// according to my approach maxProfit += prices[i] - prices[k] + prices[k] - prices[j] = prices[i] - prices[j] 

// This proves that we don't need to keep minimum we can just sell wheneven we get the higher prices and keep that as minimum

// also last day will work as minimum becauses if prices whenever we encounter higher prices than the last one we sell the stock.

class Solution
{
    public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};
int main()
{
    return 0;
}