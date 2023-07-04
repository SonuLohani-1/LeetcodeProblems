#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    return 0;
}