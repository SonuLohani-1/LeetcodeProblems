#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 17 on Leetcode - Letter Combinations of a Phone Number
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// The idea is to use recursion and backtracking to solve this problem
// We will use a map to store the mapping of the digits to the letters
// We will use a string to store the current combination
// We will use a vector of strings to store the final answer
// We will use a function to solve this problem
// The function will take the digits, the map, the current combination and the final answer as the parameters
// The function will check if the current combination is of the same length as the digits
// If yes, then we will push the current combination to the final answer
// Else, we will iterate over the letters corresponding to the current digit
// We will append the current letter to the current combination
// We will call the function again with the next digit and the current combination
// We will remove the last letter from the current combination
// We will return the final answer
// In the main function, we will call the function with the digits, the map, the current combination and the final answer
// We will return the final answer



class Solution
{
    public:
        vector<string> letterCombinations(string digits)
        {
            map<char, string> m;
            m['2'] = "abc";
            m['3'] = "def";
            m['4'] = "ghi";
            m['5'] = "jkl";
            m['6'] = "mno";
            m['7'] = "pqrs";
            m['8'] = "tuv";
            m['9'] = "wxyz";
            vector<string> ans;
            if(digits.size() == 0)
            {
                return ans;
            }
            string s = "";
            solve(digits, m, s, ans);
            return ans;
        }
        void solve(string digits, map<char, string> m, string s, vector<string> &ans)
        {
            if(s.size() == digits.size())
            {
                ans.push_back(s);
                return;
            }
            for(auto x : m[digits[s.size()]])
            {
                s.push_back(x);
                solve(digits, m, s, ans);
                s.pop_back();
            }
        }
};
int main()
{
    return 0;
}
