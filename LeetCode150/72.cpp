#include <bits/stdc++.h>
using namespace std;
// This is the bottom up dp solution
// Basic Idea:
// we keep two pointers i and j for word1 and word2 if both are same we move to i+1, j+1
// If both are different we have 3 options either make them them same or insert a character or delete a character all of them makes 1 action and pointers move accordingly
// first change the character it moves to (i+1, j+1)
// second remove a character it moves to (i+1, j)
// third insert a character it moves to (i, j+1) (Note we are not actually inserting or deleting anything we are just counting that this would happen if we do that)
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 1000)); // I am keeping value thousand because the maximum length is 500 
        for(int i = 0; i <= m; i++)
        {
            dp[i][n] = m-i;
        }
        for(int i = 0; i <= n; i++)
        {
            dp[m][i] = n-i;
        }

        for(int i = m-1; i >=0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                if(word1[i] == word2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
int main()
{
    return 0;
}