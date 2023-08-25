#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 67 on leetcode - Add Binary
// https://leetcode.com/problems/add-binary/

// The idea is to add the two strings from the end and keep track of the carry
// If the carry is 1 then add it to the result string

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length()-1, j = b.length()-1, carry = 0;
        while(i >= 0 || j >= 0 || carry){
            int sum = 0;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            sum += carry;
            carry = sum/2;
            sum = sum%2;
            res = to_string(sum) + res;
        }
        return res;
    }
};

// This was my first solution:
class Solution {
public:
    string addBinary(string a, string b) {
        while(a.size() < b.size())
        {
            a = "0" + a;
        }

        while(b.size() < a.size())
        {
            b = "0" + b;
        }
        
        int n = a.size();
        string ans = "";
        int carry = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int x = a[i] - '0';
            int y = b[i] - '0';
            ans = to_string(x^y^carry) + ans;
            carry = (x&y) | (x&carry) | (y&carry); 
        }
        if(carry) ans = "1" + ans;
        return ans;
    }
    
};
int main()
{
    
}