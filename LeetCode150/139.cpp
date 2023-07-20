#include <bits/stdc++.h>
using namespace std;

// This is the first solution mentioned in the editorial BFS
// Time Complexity O(n^3 + m*k)
// Space Complexity O(n + m*k)
class Solution1
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> queue;
        vector<bool> seen(s.length(), false);
        queue.push(0);

        while (!queue.empty())
        {
            int start = queue.front();
            queue.pop();

            if (start == s.length())
            {
                return true;
            }

            for (int end = start + 1; end <= s.length(); end++)
            {
                if (seen[end])
                {
                    continue;
                }

                if (words.find(s.substr(start, end - start)) != words.end())
                {
                    queue.push(end);
                    seen[end] = true;
                }
            }
        }
        return false;
    }
};

// This is the top-down dp solution
class Solution2
{
    vector<int> memo;
    vector<string> wordDict;
    string s;

    bool wordBreak(string s, vector<string> &wordDict)
    {
        memo = vector(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return dp(s.length() - 1);
    }

    bool dp(int i)
    {
        if (i < 0)
            return true;

        if (memo[i] != -1)
        {
            return memo[i] == 1;
        }

        for (string word : wordDict)
        {
            int currSize = word.length();

            // Handle out of bounds case
            if (i - currSize + 1 < 0)
            {
                continue;
            }

            if (s.substr(i - currSize + 1, currSize) == word && dp(i - currSize))
            {
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }
};

// This is the bottom up dp solution also known as tabulization
class Solution3
{
    public:

    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[s.length()] = true;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for(int j = 0; j < wordDict.size(); j++)
            {
                int len = wordDict[j].size();
                if((i + len) <= s.length() && s.substr(i, len) == wordDict[j] && dp[i + len] == true)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
int main()
{
    string s = "leetycode";
    vector<string> wordDict = {"leet", "leety", "code"};
    Solution3 solution;
    bool ans = solution.wordBreak(s, wordDict);
    cout << ans << endl;
    return 0;
}
