#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 72 on leetcode - Edit Distance
// https://leetcode.com/problems/edit-distance/

// This is the bottom up dp solution
// Basic Idea:
// we keep two pointers i and j for word1 and word2 if both are same we move to i+1, j+1
// If both are different we have 3 options either make them them same or insert a character or delete a character all of them makes 1 action and pointers move accordingly
// first change the character it moves to (i+1, j+1)
// second remove a character it moves to (i+1, j)
// third insert a character it moves to (i, j+1) (Note we are not actually inserting or deleting anything we are just counting that this would happen if we do that)


// This is the recursive solution 
// I have also done memoization in this solution
class Solution {
private:
    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &memo)
    {
        // if word2 still has something then we have to delete all;
        if(i == word1.length()) return word2.length() - j;

        // if word1 has still something then we have to insert all;
        if(j == word2.length()) return word1.length() - i;

        if(memo[i][j] != -1) return memo[i][j];
        int replace_count = (word1[i] != word2[j]) + helper(word1, word2, i+1, j+1, memo);
        int insert_count = 1 + helper(word1, word2, i, j+1, memo);
        int delete_count = 1 + helper(word1, word2, i+1, j, memo);

        return memo[i][j] = min(replace_count, min(insert_count, delete_count));
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length()+1, vector<int>(word2.length()+1, -1));
        return helper(word1, word2, 0, 0, memo);
    }
};

// This is the bottom up dp solution
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

// This is the space optimized solution
// This is the true dp solution bottom up
// I have also done the space optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();

        //vector<vector<int>> dp(l1+1, vector<int>(l2+1, 1000));
        vector<int> row(l2+1, 1000);

        // filling the last row of the dp table
        for(int i = 0; i <= l2; i++)
        {
            row[i] = l2 - i;
        }

        // filling the last col of the dp table
        // for(int i = 0; i < l1; i++)
        // {
        //     dp[i][l2] = l1 - i;
        // }

        for(int i = l1-1; i >= 0; i--)
        {
            vector<int> curr(l2+1, 1000);
            curr[l2] = l1 - i;
            for(int j = l2-1; j >= 0; j--)
            {
                if(word1[i] == word2[j])
                    curr[j] = row[j+1];
                else
                    curr[j] = 1 + min(row[j+1], min(row[j], curr[j+1]));
            }
            row = curr;
        }
        return row[0];
    }

};


int main()
{
    return 0;
}