#include<bits/stdc++.h>
using namespace std;    
// This is the solution for the problem 123 on leetcode - buy and sell stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// The idea is to find the maximum profit that can be made by buying and selling the stock atmost 2 times
// We can do this by finding the maximum profit that can be made by buying and selling the stock atmost 1 time
// and then finding the maximum profit that can be made by buying and selling the stock atmost 1 time in the reverse direction
// and then adding the two profits to get the maximum profit that can be made by buying and selling the stock atmost 2 times
// This trick works because we can only buy and sell the stock atmost 2 times
// So, we can buy and sell the stock atmost 1 time and then buy and sell the stock atmost 1 time in the reverse direction
// to get the maximum profit that can be made by buying and selling the stock atmost 2 times
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) {
            return 0;
        }
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int minPrice = prices[0];
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        int maxPrice = prices[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        int maxProfit = 0;
        for(int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, left[i] + right[i]);
        }
        return maxProfit;
    }
};