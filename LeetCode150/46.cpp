#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 46 on Leetcode - Permutations
// https://leetcode.com/problems/permutations/

// This is the first method I thought of
// here I have used the fact that we can use any element as the first element of the permutation
// so we will iterate over the elements of the array
class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1)
        return {{nums[0]}};
        vector<vector<int>> ans;
       for(int i = 0; i<nums.size(); i++)
       {
           vector<int> arr = nums;
           arr.erase(arr.begin()+i);
           for(auto permutation : permute(arr) )
           {
               permutation.insert(permutation.begin(), nums[i]);
               ans.push_back(permutation);
           }
       }
      return ans;
    }
};

// This is the more efficient method given in the editorial
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> curr = {};
       backtrack(curr, ans, nums);
       return ans;
    }

    void backtrack(vector<int>& curr, vector<vector<int>> & ans, vector<int>& nums)
    {
        if(curr.size() == nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int num : nums)
        {
            if(find(curr.begin(), curr.end(), num) == curr.end())
            {
                curr.push_back(num);
                backtrack(curr, ans, nums);
                curr.pop_back();
            }
        }
    }
};

// This is the most concise and efficient solution if we are familiar with next_permutation function but this problem is actually about how permutation is generated
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do
        {
            ans.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

int main()
{
    return 0;
}