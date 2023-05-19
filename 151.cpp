#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) {
        stack<string> st;
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == ' ')
            continue;

            string str;

            while(i < s.length() && s[i] != ' ')
            {
                str += s[i];
                i++;
            }
            st.push(str);
        }
        string ans;
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
            if(!st.empty())
            ans += " ";

        }
        return ans;
    }
int main()
{
    string s;
    cin >> s;
    s = reverseWords(s);
    cout << s;
    return 0;
}