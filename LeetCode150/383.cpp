#include <bits/stdc++.h>
using namespace std;

// This is the solution of the leetcode problem 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

// The intuition behind this problem is to use a hashmap to store the
// frequency of each character in the magazine string and then check
// if the ransomNote string can be formed from the magazine string.

class Solution
{
    public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> freq;
        for (char ch : magazine)
        {
            freq[ch]++;
        }
        for (char ch : ransomNote)
        {
            if (freq[ch] == 0)
                return false;
            freq[ch]--;
        }

        return true;
    }
};
int main()
{
    return 0;
}