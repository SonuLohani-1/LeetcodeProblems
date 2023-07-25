#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 205. Isomorphic Strings in LeetCode
// https://leetcode.com/problems/isomorphic-strings/

// The intuition behind this problem is that we can map the characters of the first string to the second string
// and if we find a character that is already mapped to another character then we can return false.

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for (int i = 0; i < s.size(); i++)
        {

            // If the character is not present in the map then we can map it to the character in the second string
            if (mp.find(s[i]) == mp.end())
            {
                if (st.find(t[i]) != st.end())
                {
                    return false;
                }
                mp[s[i]] = t[i];
                st.insert(t[i]);
            }

            // If the character is present in the map then we can check if it is mapped to the same character in the second string
            else
            {
                if (mp[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isIsomorphic("badc", "baba") << endl;
    return 0;
}