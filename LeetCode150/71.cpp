#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path)
{
    stringstream ss(path);
    stack<string> st;
    string ans = "";
    char del = '/';
    while (!ss.eof()) {
        string word;
        getline(ss, word, del);
        if(word == "..")
        {
            if(!st.empty())
            {
                st.pop();
                st.pop();
            }

        }
        else if(word != "" &&  word != ".")
        {
            st.push("/");
            st.push(word);
        }
    }
    if(st.empty()) return "/";
    while(!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}
int main()
{
    cout << simplifyPath("/home//desktop//downloads/////mybooks") << endl;
    return 0;
}