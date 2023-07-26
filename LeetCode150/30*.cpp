#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 30 on Leetcode - Substring with Concatenation of All Words.
// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

// The idea is to use a map.
// We will store the frequency of each word in the map.
// Then we will iterate over the string.
// We will check if the current word is present in the map.
// If it is, then we will check if the frequency of the current word is greater than 0.
// If it is, then we will decrement the frequency of the current word.
// Else we will increment the frequency of the current word.
// If the current word is not present in the map, then we will continue.
// If the size of the window becomes equal to the size of the words, then we will push the starting index of the window in the answer.
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        map<string, int> m;
        for (int i = 0; i < words.size(); i++)
            m[words[i]]++;
        vector<int> ans;
        int n = s.size(), m1 = words.size(), m2 = words[0].size();
        for (int i = 0; i < n - m1 * m2 + 1; i++)
        {
            map<string, int> m3;
            int j = i;
            while (j < i + m1 * m2)
            {
                string str = s.substr(j, m2);
                if (m.find(str) != m.end())
                {
                    if (m3[str] < m[str])
                        m3[str]++;
                    else
                        break;
                }
                else
                    break;
                j += m2;
            }
            if (j == i + m1 * m2)
                ans.push_back(i);
        }
        return ans;
    }
};

// this solution is not accepted on leetcode because of TLE.
// A more efficient solution is below.
// this solution uses a sliding window.
// time complexity: O(n)
// space complexity: O(n)
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> m;
        for (const string &word : words)
            m[word]++;

        vector<int> ans;
        int n = s.size();
        int num_words = words.size();
        int word_length = words[0].size();

        int window_size = num_words * word_length;

        for (int i = 0; i < word_length; i++)
        {
            unordered_map<string, int> m3;
            int start = i, end = i;

            while (end + word_length <= n)
            {
                string str = s.substr(end, word_length);
                end += word_length;

                if (m.find(str) != m.end())
                {
                    m3[str]++;
                    while (m3[str] > m[str])
                    {
                        m3[s.substr(start, word_length)]--;
                        start += word_length;
                    }

                    if (end - start == window_size)
                        ans.push_back(start);
                }
                else
                {
                    m3.clear();
                    start = end;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}