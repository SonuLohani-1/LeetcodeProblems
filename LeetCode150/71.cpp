#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem simplify path on leetcode
// https://leetcode.com/problems/simplify-path/

// This was my first approach
class Solution
{
public:
    string simplifyPath(string path)
    {
        stringstream ss(path);
        stack<string> st;
        string ans = "";
        char del = '/';
        while (!ss.eof())
        {
            string word;
            getline(ss, word, del);
            if (word == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                    st.pop();
                }
            }
            else if (word != "" && word != ".")
            {
                st.push("/");
                st.push(word);
            }
        }
        if (st.empty())
            return "/";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// This is a better approach
// The idea is to use a stack and then for each word in the path we check if it is equal to ".." then we pop the top of the stack and if it is equal to "." then we do nothing and if it is not equal to either of them then we push it into the stack.
// The time complexity = O(n)
// Space complexity = O(n)
class Solution
{
public:
    string simplifyPath(string path)
    {
        stringstream ss(path);
        stack<string> st;
        string ans = "";
        char del = '/';
        while (!ss.eof())
        {
            string word;
            getline(ss, word, del);
            if (word == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else if (word != "" && word != ".")
            {
                st.push(word);
            }
        }
        if (st.empty())
            return "/";
        while (!st.empty())
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
int main()
{
    Solution sol;
    cout << sol.simplifyPath("/home//desktop//downloads/////mybooks") << endl;
    return 0;
}