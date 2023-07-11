#include <bits/stdc++.h>
using namespace std;
string multiplyString(string s, int multiplier)
{
    string res = "";
    for (int i = 0; i < multiplier; i++)
    {
        res += s;
    }
    return res;
}
string decodeString(string s)
{
    stack<char> chars;
    string res = "";
    for(int i = 0; i<s.length(); i++)
    {

        if (s[i] == ']')
        {
            string temp = "";
            while (chars.top() != '[')
            {
                temp = chars.top() + temp;
                chars.pop();
            }
            chars.pop(); // now we have to pop '['

            // Now finding the number
            string multiplier = "";
            while (!chars.empty() && chars.top() - '0' <= 9 && chars.top() - '0' >= 0)
            {
                multiplier = chars.top() + multiplier;
                chars.pop();
            }

            string decoded = multiplyString(temp, stoi(multiplier));

            for (auto it : decoded)
                chars.push(it);
        }

        else
            chars.push(s[i]);
    }

    while (!chars.empty())
    {
        res = chars.top() + res;
        chars.pop();
    }

    return res;
}
int main()
{
    string res = decodeString("3[a2[c]]");
    cout << res << endl;
    return 0;
}