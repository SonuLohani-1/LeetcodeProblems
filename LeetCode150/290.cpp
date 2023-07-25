#include <bits/stdc++.h>
using namespace std;
// This is the solutio of the 290. Word Pattern in LeetCode
// https://leetcode.com/problems/word-pattern/

// The intuition behind this problem is that we can map the characters of the first string to the second string
// and if we find a character that is already mapped to another character then we can return false.
// same goes for the second string to the first string.

// This is the solution I came up with
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        // we can make the map of pattern's char and s we will need to split the string on the basis of " "
        stringstream ss(s);
        unordered_map<char, string> map1; // map char of pattern to word in s
        unordered_map<string, char> map2; // do opposite of map1
        int ptr = 0;
        int wordCount = 0;
        while (!ss.eof())
        {
            string word;
            getline(ss, word, ' ');
            if (map1.find(pattern[ptr]) != map1.end() || map2.find(word) != map2.end()) // it simply means we found the curr in at least one of the maps
            {
                if (map1[pattern[ptr]] != word or map2[word] != pattern[ptr])
                    return false;
            }
            else
            {
                map1[pattern[ptr]] = word;
                map2[word] = pattern[ptr];
            }
            ptr++;
            wordCount++;
        }
        if (wordCount != pattern.length())
            return false;
        return true;
    }
};

// A more elegant solution
class Solution2
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;
        stringstream ss(s);
        int i = 0;
        for (string word; ss >> word; i++)
        {
            if (mp1[pattern[i]] != mp2[word])
                return false;
            mp1[pattern[i]] = mp2[word] = i + 1;
        }
        return i == pattern.size();
    }
};

int main()
{
    return 0;
}