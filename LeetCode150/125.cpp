#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem Valid Palindrome in LeetCode
// https://leetcode.com/problems/valid-palindrome/

// The logic is to use two pointers, one from the start and one from the end
// and check if the characters are alphanumeric or not
// if they are alphanumeric then check if they are equal or not
// if they are not equal then return false
// if they are equal then increment the start pointer and decrement the end pointer
// if they are not alphanumeric then increment the start pointer or decrement the end pointer 
// depending on which one is not alphanumeric
// if the start pointer is greater than the end pointer then return true
// else return false

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while(i < j)
        {
            if(!isalnum(s[i]))
                i++;
            else if(!isalnum(s[j]))
                j--;
            else if(tolower(s[i]) != tolower(s[j]))
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}