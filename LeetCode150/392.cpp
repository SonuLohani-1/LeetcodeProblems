#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem is Subsequence in LeetCode
// https://leetcode.com/problems/is-subsequence/

// the logic for solving the problem using recursion is to check if the first character of the string s is equal to the first character of the string t
// if they are equal then increment the index of the string s and the string t
// if they are not equal then increment the index of the string t
// if the index of the string s is equal to the length of the string s then return true
// if the index of the string t is equal to the length of the string t then return false
// else return the function call with the incremented index of the string s and the string t

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                j++;
        }
        if(i == n)
            return true;
        return false;
    }
};
int main()
{
    return 0;
}