#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();

        if(n + m != l)
        {
             return false;
        }

        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[n][m] = true;

        for(int i = n; i >= 0; i--)
        {
            for(int j = m; j >= 0; j--)
            {
                if(i < n && s1[i] == s3[i + j] && dp[i+1][j])
                {
                    dp[i][j] = true;
                }
                else if(j < m && s2[j] == s3[i+j] && dp[i][j+1])
                {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
        
    }
};

// This is the memoization solution (top-down)
// This is exceeding the time limit
class Solution2
{
private:
    bool dfs(string s1, string s2, string s3, int i, int j, vector<vector<int>> dp)
    {
        if(i == s1.length() && j == s2.length()) 
        {
            return true;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if(i < s1.length() && s1[i] == s3[i+j] && dfs(s1, s2, s3, i+1, j, dp))
        {
            return dp[i][j] = true;
        }

        if(j < s2.length() && s2[j] == s3[i+j] && dfs(s1, s2, s3, i, j+1, dp))
        {
            return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return dfs(s1, s2, s3, 0, 0, dp);
    }
};
 int main()
{
    return 0;
}