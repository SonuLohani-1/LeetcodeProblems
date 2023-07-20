#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem Best time to buy and sell stocks on leetcode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// The logic for the above solution is that we will keep track of the minimum element and the maximum profit.
class Solution
{
    public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > maxProfit)
            {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};
int main()
{
    return 0;
}