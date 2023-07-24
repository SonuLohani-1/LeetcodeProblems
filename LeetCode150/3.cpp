#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem Longest substring without repeating characters on leetcode
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// The intution behind this problem is that we can use sliding window to solve this problem
// We will use two pointers i and j to keep track of the window
// We will use a hashmap to store the last occurence of the character
// If the character is already present in the hashmap then we will update the value of i to the last occurence of the character + 1
// We will also update the value of the character in the hashmap to the current index

// Time complexity O(n)
// Space complexity O(n)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, res = 0;
        unordered_map<char, int> mp;
        while (j < s.size())
        {
            if (mp.find(s[j]) != mp.end())
            {
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]] = j;
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};

int main()
{
    return 0;
}