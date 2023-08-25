#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 198 on leetcode - House Robber
// https://leetcode.com/problems/house-robber/

// The solution is to use dynamic programming
// This is the most optimized solution 
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int temp = b;
            b = max(a + nums[i], b);
            a = temp;
        }
        return b;
    }
};
int main()
{
    return 0;
}