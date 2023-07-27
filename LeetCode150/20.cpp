#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem valid parenthesis string on leetcode
// https://leetcode.com/problems/valid-parenthesis-string/

// This was my first approach
// This solution uses stack to store the opening brackets and then for each closing bracket we check if the top of the stack is the corresponding opening bracket or not and if it is then we pop the top of the stack and if it is not then we return false.
// The time complexity = O(n)
// Space complexity = O(n)

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                    return false;

                else if (st.top() == '(')
                {
                    st.pop();
                }
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (st.empty())
                    return false;
                else if (st.top() == '{')
                {

                    st.pop();
                }
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (st.empty())
                    return false;

                else if (st.top() == '[')
                {

                    st.pop();
                }
                else
                    return false;
            }
        }
        return st.empty() == 1;
    }
};

// This is a better approach
// In this way we can decrease number of comparisions by using a map to store the corresponding closing bracket for each opening bracket.
// The time complexity = O(n)
// Space complexity = O(n)

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            // if we have open bracket then we push corresponding close bracket into the stack
            if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            else if (c == '(')
                st.push(')');
            else if (!st.empty() and c == st.top())
                st.pop();
            else
                return false;
        }
        return (st.empty());
    }
};

int main()
{
    return 0;
}