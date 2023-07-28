#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 150. Evaluate Reverse Polish Notation in LeetCode
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

// The idea is to use a stack to store the operands and when we encounter an operator we pop the top two elements from the stack and perform the operation and push the result back to the stack.
// Time complexity: O(n)
// Space complexity: O(n)

int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (const string& token : tokens) {
        if (token == "/" || token == "+" || token == "-" || token == "*") {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result;
            if (token == "/") {
                result = operand1 / operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "+") {
                result = operand1 + operand2;
            } else {
                result = operand1 - operand2;
            }
            st.push(result);
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main()
{
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens) << endl;
    return 0;
}