#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 201 on Leetcode - Bitwise AND of Numbers Range
// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// The efficient solution requires observation that the prefix of common set bits without any changing bits  in between will remain at the last so the answer will be either less than left or equal to left
// so starting from the right we can drop the last bit until it becomes <= left at that moment we can return the ans
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left)
        {
            right = (right) & (right - 1);
        }
        return right;
    }
};
int main()
{
    Solution solution;
    int ans = solution.rangeBitwiseAnd(16, 17);
    cout << ans << endl;
    return 0;
}