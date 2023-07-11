#include <bits/stdc++.h>
using namespace std;
// This is the recursive solution and the time limit is exceeding;
class Solution
{
private:
    int helper(vector<int> &coins, int amount, int i)
    {
        if(amount == 0) return 0;
        if(i == coins.size()) return int(1e9);
        if(amount < 0) return int(1e9);
        int take = 1 + helper(coins, amount - coins[i], i);
        int notTake = helper(coins, amount, i + 1);
        return min(take, notTake);
    }
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = helper(coins, amount, 0);
        if(ans < int(1e9)) return ans;
        return -1;
    }
};

// this is the bottom up solution using dynamic programming
class Solution2
{
    private:
        int coinChange(vector<int> &coins, int amount)
        {
            vector<int> dp(amount + 1, amount +1);
            dp[0] = 0;
            for(int i = 1; i <= amount; amount++)
            {
                for(auto coin : coins)
                {
                    if(i - coin >= 0)
                        dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
            return dp[amount] < amount ? dp[amount]: -1;
            
        }
};
int main()
{

    return 0;
}