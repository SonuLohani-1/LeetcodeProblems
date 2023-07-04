#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> ans;
    void backtrack(vector<int> &candidates, int target, int idx, vector<int> currCombination)
    {
        if (target == 0)
        {
            ans.push_back(currCombination);
            return;
        }
        if(target < 0 || idx == candidates.size())
            return;

        currCombination.push_back(candidates[idx]);
        backtrack(candidates, target - candidates[idx], idx, currCombination);

        candidates.pop_back();
        backtrack(candidates, target, idx + 1, currCombination);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrack(candidates, target, 0, {});
        return ans;
    }
};
int main()
{
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> combinations = solution.combinationSum(candidates, 7);
    for(auto combination : combinations)
    {
        for(auto it : combination)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}