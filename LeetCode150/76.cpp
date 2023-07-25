#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 76 in Leetcode - Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/



class Solution
{
    public:
        string minWindow(string s, string t)
        {
            if(t == "") return "";

            unordered_map<char, int> countT;
            unordered_map<char, int> window;

            for(auto c : t)
            {
                countT[c]++;
            }

            int have = 0, need = countT.size();
            vector<int> res = {-1, -1};
            int resLen = INT_MAX;
            int left = 0;
            for(int i = 0; i < s.length(); i++)
            {
               char c = s[i];
               window[c]++;

               if(countT.find(c) != countT.end() && window[c] == countT[c])
               {
                   have++;
               }

               while(have == need)
               {
                    if(i - left + 1 < resLen)
                    {
                        resLen = i - left + 1;
                        res = {left, i};
                    }

                    // remove the character at the left pointer
                    window[s[left]]--;
                    if(countT.find(s[left]) != countT.end() && window[s[left]] < countT[s[left]])
                    {
                        have--;
                    }
                    left++;
               }

            }
            if(res[0] == -1) return "";
            return s.substr(res[0], res[1] - res[0] + 1);
        }
};
int main()
{
    return 0;
}