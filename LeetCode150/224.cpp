#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem basic calculator on leetcode
// https://leetcode.com/problems/basic-calculator/?envType=study-plan-v2&envId=top-interview-150

// The idea is to use stack and keep on pushing the numbers and operators in the stack
// If we encounter a closing bracket, then we pop the elements from the stack until we encounter an opening bracket
// We keep on adding the popped elements to the sum
// We push the sum in the stack
// Time complexity - O(n)
// Space complexity - O(n)

class Solution
{
public:
    int calculate(string s)
    {
        stack<int> st;
        int sum = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (i < s.length() && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += sign * num;
            }
            else if (s[i] == '+')
            {
                sign = 1;
            }
            else if (s[i] == '-')
            {
                sign = -1;
            }
            else if (s[i] == '(')
            {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                sum *= st.top();
                st.pop();
                sum += st.top();
                st.pop();
            }
        }

        return sum;
    }
};
int main()
{
    return 0;
}