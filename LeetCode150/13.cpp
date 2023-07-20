#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 13 on leetcode Roman to Integer
// https://leetcode.com/problems/roman-to-integer/

// The intuition for this problem is that we can use a map to store the value of each roman character
// and then we can traverse the string and add the value of the current character to the ans
// if the value of the current character is less than the value of the next character then we can subtract the value of the current character from the ans
// The time complexity of this solution is O(n) and space complexity is O(1)

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> RomVal;
        int ans = 0;
        int prevVal = 0;
        RomVal['I'] = 1;
        RomVal['V'] = 5;
        RomVal['X'] = 10;
        RomVal['L'] = 50;
        RomVal['C'] = 100;
        RomVal['D'] = 500;
        RomVal['M'] = 1000;
        for(int i = s.size()-1; i>=0; i--)
        {
           if(prevVal > RomVal[s[i]])
           {
               ans = ans - RomVal[s[i]];
           }
            else
            {
                ans = ans + RomVal[s[i]];
            }
            prevVal = RomVal[s[i]];
        }
        return ans;
        
    }
};
int main()
{
    return 0;
}