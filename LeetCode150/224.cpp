#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem basic calculator on leetcode
// https://leetcode.com/problems/basic-calculator/?envType=study-plan-v2&envId=top-interview-150

class Solution
{
public:
    int calculate(string s)
    {
        stack<string> st;
        for(int i = 0;  i < s.length(); i++)
        {
            string c = to_string(s[i]);
            if(c == "*")
            {
                int first = stoi(st.top());
                int second = s[i+1] - '0'; i++;
                st.pop();
                st.push(to_string(first*second));
            }

            else if(c == "/")
            {
                int first = stoi(st.top());
                int second = s[i+1] - '0'; i++;
                st.pop();
                st.push(to_string (first / second));
            }

            else if(c == ")")
            {
                int bracket_val = 0;
                while(st.top() != "(")
                {
                    bracket_val += stoi(st.top());
                    st.pop();
                }
                st.push(to_string(bracket_val));
            }


        }
    }
};
int main()
{
    return 0;
}