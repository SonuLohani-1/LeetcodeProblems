#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 9 on Leetcode - Palindrome Number
// https://leetcode.com/problems/palindrome-number/

// The solution is to reverse the number and check if it is equal to the original number
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int temp = x;
        long long int rev = 0;
        while(temp > 0)
        {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        return rev == x;
    }
};

// my first solution
class Solution {
private:
    bool isPalindrome(string s)
    {
        for(int i = 0; i<s.size()/2; i++)
        {
            if(s[i] != s[s.size() - 1  - i])
                return false;
        }
        return true;
    }
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string temp = to_string(x);
        return isPalindrome(temp);
    }
};
int main()
{
    return 0;
}