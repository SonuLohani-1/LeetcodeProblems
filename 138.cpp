#include <bits/stdc++.h>
using namespace std;
vector<int> countBits(int n)
{
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        int m = i;
        while (m)
        {
            m = m & (m - 1);
            count++;
        }
        ans.push_back(count);
    }
    return ans;
}

int main()
{
    vector<int> bits = countBits(5);
    for (auto it : bits)
        cout << it << endl;

    return 0;
}