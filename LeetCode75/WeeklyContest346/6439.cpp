#include <bits/stdc++.h>
using namespace std;
int minLength(string s)
{

    queue<char> q;
    for (int i = s.length()-1; i>=0; i--)
    {
        q.push(s[i]);
    }

    int lastStepLength = 0;
    while (!q.empty())
    {
        char curr = q.front();
        q.pop();
        if (curr == 'B' && q.front() == 'A')
            q.pop();
        else if (curr == 'D' && q.front() == 'C')
            q.pop();
        else
            q.push(curr);

        // checking if still some pair is there
        queue<char> q2 = q;
        while(true)
        {
            char front = q.front();
            q.pop();
            {
                if(q.)
            }
        }

    }
    return lastStepLength;
}
int main()
{
    string s = "ABFCACDB";
    cout << minLength(s) << endl;
    return 0;
}