#include <bits/stdc++.h>
using namespace std;
vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    // idea is to sort the potions array;
    vector<int> ans;
    sort(potions.begin(), potions.end());
    for (int i = 0; i < spells.size(); i++)
    {
        int low = 0;
        int high = potions.size() - 1;
        if (long long(spells[i]) * long long(potions[low]) > success)
        {
            ans.push_back(long long (spells.size());
            continue;
        }
        if (long long(spells[i]) * long long(potions[high]) < success)
        {
            ans.push_back(0);
            continue;
        }
    }
}
int main()
{
}