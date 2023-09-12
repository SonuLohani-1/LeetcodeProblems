#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 97 on leetcode - Interleaving String
// https://leetcode.com/problems/interleaving-string/
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

// This is the tabulization solution or true dp solution
// Also doing the space optimization;
class Solution1 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;

        //vector<vector<bool>> dp(s1.length()+1, vector<bool> (s2.length()+1, 0));
        //we notice that only the row below curr row is required 
        // in this case we also need another base cases
        if(s1.length() == 0 ) return s2 == s3;
        if(s2.length() == 0 ) return s1 == s3;
        vector<bool> row(s2.length()+1, false);
    
        //dp[s1.length()][s2.length()] = true;
        row[s2.length()] = true;

        for(int i = s1.length(); i >= 0; i--)
        {
            for(int j = s2.length(); j >= 0; j--)
            {
                if(i < s1.length() && s1[i] == s3[i+j] && row[j])
                    row[j] = true;
                else if(j < s2.length() && s2[j] == s3[i+j] && row[j+1])
                    row[j] = true;
                else if(j != s2.length())
                    row[j] = false;
            }
        }
        return row[0];
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
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    Solution1 s;
    cout << s.isInterleave(s1, s2, s3) << endl;
    return 0;
}