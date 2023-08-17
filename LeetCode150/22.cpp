#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 22 on leetcode - Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

// The idea is to use backtracking to find all the possible combinations
// if the number of opening brackets is less than n then we can add an opening bracket
// if the number of closing brackets is less than the number of opening brackets then we can add a closing bracket
// The time complexity is O(2^n) and space complexity is O(n)

class Solution
{
private:
    vector<string> ans;
    void backtrack(string curr, int open, int close, int n)
    {
        if (curr.size() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }
        if (open < n)
        {
            backtrack(curr + "(", open + 1, close, n);
        }
        if (close < open)
        {
            backtrack(curr + ")", open, close + 1, n);
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        backtrack("", 0, 0, n);
        return ans;
    }
};

// we can also use DP to solve this problem
// we can use the formula
// dp[i] = "(" + dp[j] + ")" + dp[i - j - 1] for all j from 0 to i - 1
// The time complexity is O(n^2) and space complexity is O(n^2)
// This solution is not written by me
class Solution2
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
                for (string &first : dp[j])
                    for (string &second : dp[i - j - 1])
                        dp[i].push_back("(" + first + ")" + second);
        }
        return dp[n];
    }
};
int main()
{
    return 0;
}