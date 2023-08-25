#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 190 on leetcode - Reverse Bits
// https://leetcode.com/problems/reverse-bits/

// This is the solution using bit manipulation
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++)
        {
            ans = (ans << 1)^(n&1); // (ans << 1) will always have last bit zero so according to n&1 it will have zero or 1 last bit;;
            n = n >> 1;
        }
        return ans;
    }
};

int main()
{
    return 0;
}