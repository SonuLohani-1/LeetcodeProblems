#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem reverse words in a string on leetcode.
// https://leetcode.com/problems/reverse-words-in-a-string/

// The intuition is that we can use stack to reverse the words in a string. We can push the words in the stack and then pop them to get the reversed string.
// The time complexity is O(n) and the space complexity is O(n).
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                continue;

            string str;

            while (i < s.length() && s[i] != ' ')
            {
                str += s[i];
                i++;
            }
            st.push(str);
        }
        string ans;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
            if (!st.empty())
                ans += " ";
        }
        return ans;
    }
};


// this is an optimized solution in O(1) space complexity.
class Solution2
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int i = 0, j = 0;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i < n && j > 0)
                s[j++] = ' ';
            int start = j;
            while (i < n && s[i] != ' ')
                s[j++] = s[i++];
            reverse(s.begin() + start, s.begin() + j);
        }
        s.resize(j);
        reverse(s.begin(), s.end());
        return s;
    }
};


int main()
{
    return 0;
}