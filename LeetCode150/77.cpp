#include <bits/stdc++.h>
using namespace std;
// This is the first method I thought of
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

// This is the second method I thought of
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        string str;
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++)
        {
            str += "1";
        }
        while(str.length() < n)
        {
            str = "0" + str;
        }
        do
        {
            vector<int> temp;
            for(int i = 1; i <= n; i++)
            {
                if(str[i-1] == '1')
                {
                    temp.push_back(i);
                }
            }
            ans.push_back(temp);
        } while(next_permutation(str.begin(), str.end()));
        return ans;
    }
};

// This is the best approach
// The idea is to use backtracking
// We will use a function to solve this problem
// The function will take the current number, the current combination, the final answer, the current index and the target as the parameters
// The function will check if the current combination is of the same length as the target
// If yes, then we will push the current combination to the final answer
// Else, we will iterate over the numbers from the current number to the target
// We will append the current number to the current combination
// We will call the function again with the next number, the current combination, the final answer, the current index and the target
// We will remove the last number from the current combination

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int num, vector<int> temp, int index, int target)
    {
        if(temp.size() == target)
        {
            ans.push_back(temp);
            return;
        }
        for(int i = num; i <= target; i++)
        {
            temp.push_back(i);
            solve(i+1, temp, index+1, target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(1, {}, 0, n);
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