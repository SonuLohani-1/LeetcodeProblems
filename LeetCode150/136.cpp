#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 136 on leetcode - Single Number
// https://leetcode.com/problems/single-number/

// This is the solution using bit manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i]; // This way all the numbers which are present twice will cancel out each other and the only number which is present once will be left.
        }
        return ans;
    }
};
int main()
{
    return 0;
}