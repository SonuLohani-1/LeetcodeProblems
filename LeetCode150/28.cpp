#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem Find the Index of the First Occurrence in a String on leetcode.

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// The solution is very simple. We just need to find the first occurrence of the target string in the given string and then return its index.
// The time complexity is O(n*m) where n is the length of the given string and m is the length of the target string.
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            if (haystack[i] == needle[0])
            {
                int j = 0;
                while (j < m && i + j < n && haystack[i + j] == needle[j])
                    j++;
                if (j == m)
                    return i;
            }
        }
        return -1;
    }
};

// this is the explanation of the KMP algorithm.
// https://www.youtube.com/watch?v=GTJr8OvyEVQ

// If there is a mismatch then instead of comparing with the first character of the pattern we can compare with the last character of the prefix of the pattern which is also a suffix of the pattern. (In simple words till how much we can skip the pattern because it is also there at the end of the pattern matched till now.)

// The time complexity of the KMP algorithm is O(n+m) where n is the length of the given string and m is the length of the target string.
class Solution2
{
private:
    // this is the function to calculate the lps(longest prefix suffix) array.
    void lpsArray(string needle, int m, vector<int> &lps)
    {
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m)
        {
            if (needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0)
            return 0;
        vector<int> lps(m);
        lpsArray(needle, m, lps);
        int i = 0, j = 0;
        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == m)
                return i - j;
            else if (i < n && haystack[i] != needle[j])
            {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
};
int main()
{
    return 0;
}