#include <bits/stdc++.h>
using namespace std;
bool f(string s, int n, int idx)
{
    if (n == 0 && idx == s.length() - 1)
        return true;

    for (int i = idx; i < s.length() - 1; i++)
    {
        string curr = "";
        for (int j = i; j < s.length(); j++)
        {
            curr += s[j];
            int num = stoi(curr);
            if (num > n)
                break;
            if (f(s, n - num, j + 1))
                return true;
        }
    }

    return false;
}

int main()
{
    cout << f("1296", 36, 0) << endl;
    return 0;
}