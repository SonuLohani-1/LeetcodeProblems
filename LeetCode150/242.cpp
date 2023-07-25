#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 242. Valid Anagram in LeetCode
// https://leetcode.com/problems/valid-anagram/

// we can create a map of the characters of the first string and then we can check if the second string contains the same characters
// as the first string and if the count of the characters is also same then we can return true else false

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (mp.find(t[i]) == mp.end())
            {
                return false;
            }
            mp[t[i]]--;
        }
        for (auto it : mp)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// Follow up: What if the inputs contain unicode characters? How would you adapt your solution to such case?
// The above solution will work for the unicode characters as well because we are using the unordered_map and it can store the unicode characters as well
int main()
{
    return 0;
}