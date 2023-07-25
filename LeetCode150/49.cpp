#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 49. Group Anagrams in LeetCode
// https://leetcode.com/problems/group-anagrams/

// The intuition behind this problem is that we can sort the words and then we can group the words that are anagrams of each other

// This is the solution I came up with
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> map;
    vector<vector<string>> ans;
    for(int i = 0; i<strs.size(); i++)
    {
        string currWord = strs[i];
        sort(currWord.begin(), currWord.end());
        map[currWord].push_back(strs[i]);
    }
    for(auto it : map)
    {
        vector<string> anagrams;
        for(auto it2 : it.second)
        {
            anagrams.push_back(it2);
        }
        ans.push_back(anagrams);
    }
    return ans;
}

// A more elegant solution
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp)
        {
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
int main()
{
    return 0;
}