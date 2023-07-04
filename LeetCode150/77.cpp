#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> ans;
    void combinations(int n, int k, int i, vector<int> arr)
    {
        if (arr.size() == k)
        {
            ans.push_back(arr);
            return;
        }
        if (i > n)
            return;
            
        arr.push_back(i);
        combinations(n, k, i + 1, arr);
        arr.pop_back();
        combinations(n, k, i + 1, arr);
    }

public:
    vector<vector<int>> combine(int n, int k)
    {

        combinations(n, k, 1, {});
        return ans;
    }
};
int main()
{
    Solution solution;
    vector<vector<int>> combinations = solution.combine(4, 2);
    for (auto combination : combinations)
    {
        for (auto it : combination)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}