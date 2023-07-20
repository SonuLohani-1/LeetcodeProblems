#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem Longest Common Prefix on leetcode.
// https://leetcode.com/problems/longest-common-prefix/

// The logic is very simple. We just need to find the longest common prefix of the first two strings and then use that to find the longest common prefix of the next string and so on.
// The time complexity is O(n*m) where n is the number of strings and m is the length of the longest string.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";
        string ans = strs[0];
        for(int i = 1; i < n; i++)
        {
            int j = 0;
            while(j < ans.length() && j < strs[i].length() && ans[j] == strs[i][j])
                j++;
            ans = ans.substr(0, j);
        }
        return ans;
    }
};
int main()
{
    return 0;
}