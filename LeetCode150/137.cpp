#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 137 on leetcode - Single Number II
// https://leetcode.com/problems/single-number-ii/

// The idea is to check if each 32 bits has how many bits
// if there are multiple of 3 bits drop it
// else take it (here by bit I mean set bit)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            int count = 0;
            for(auto num : nums)
            {
                count += num >> i & 1;
            }
            count = count % 3;
            ans |= count << i;
        }
        return ans;
    }
};
int main()
{
    return 0;
}