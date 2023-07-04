#include <bits/stdc++.h>
using namespace std;
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