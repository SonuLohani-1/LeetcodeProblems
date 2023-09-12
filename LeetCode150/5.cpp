#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 5 on leetcode - Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/


// This is the brute force solution of the problem.
// we are considering every substring starting from the longest one
// so that as soon as we find the longest substring we can exit.
class Solution {   
private:
    int check(string &s, int i, int j)
    {
        int left = i;
        int right = j-1;
        while(left < right)
        {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
public:
    string longestPalindrome(string s) {
        for(int i = s.length(); i>0; i--) // i = length of substring
        {
            for(int j = 0; j <= s.length()-i; j++)
            {
                if(check (s, j, j + i))
                {
                    return s.substr(j, i);
                }
            }
        }
        return "";
    }
};

// This is the dynamic programming approach for the problem for this problem.
// Time complexity = O(n^2);
// Space complexity = O(n^2);
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans[] = {0, 0};
        for(int i= 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                ans[0] = i;
                ans[1] = i+1;
            }
        }

        for(int diff = 2; diff < n; diff++)
        {
            for(int i = 0; i < n - diff; i++)
            {
                int j = i + diff;
                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return s.substr(ans[0], ans[1] - ans[0]+1);
    }
};

// This is more space optimized than dp solution
// this method uses expanding around center 
class Solution {
private:
    int expand(string s, int i, int j)
    {
        int left = i;
        int right = j;
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        };
        return right - left - 1; // since when the loop exits s[l] != s[r] so length = r - l - 1 instead of r - l + 1;
    }
public:
    string longestPalindrome(string s) {
        int ans[] = {0, 0};
        for(int i = 0; i < s.length(); i++)
        {
            int oddLength = expand(s, i, i);
            if(oddLength > ans[1] - ans[0] + 1)
            {
                int dist = oddLength/2;
                ans[0] = i - dist;
                ans[1] = i + dist;
            }
            int evenLength = expand(s, i, i+1);
            if(evenLength > ans[1] - ans[0] + 1)
            {
                int dist = evenLength/2 - 1;
                ans[0] = i - dist;
                ans[1] = i + 1 + dist;
            }
        }

        return s.substr(ans[0], ans[1]-ans[0]+1);
    }
};
int main()
{
    return 0;
}