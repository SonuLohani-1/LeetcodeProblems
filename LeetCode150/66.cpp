#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 66 on leetcode - Plus One
// https://leetcode.com/problems/plus-one/

// The problem is simple we will start from the last and if we encounter any digits which is 9 we make it zero otherwise we return by adding 1 to that digits
// If the iteration is reached to the end we make the first digit 1 and push 1 0 to the end of the digits and return it.
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--)
        {
            if(digits[i] != 9) 
            {
                digits[i] = digits[i] + 1;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};

int main()
{
    return 0;
}