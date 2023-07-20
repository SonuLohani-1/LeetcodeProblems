#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem Length of Last Word on leetcode.
// https://leetcode.com/problems/length-of-last-word/
// The solution is very simple. We just need to find the last word in the string and then return its length.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if(s[n-1] == ' ')
            while(s[n-1] == ' ' && n)
                n--;
        
        int ans = 0;
        while(n && s[n-1] != ' ') 
        {
            ans++;
            n--;
        }
        
        return ans;
    }
};

int main()
{
    return 0;
}