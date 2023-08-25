#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 191 on leetcode - Number of 1 Bits
// https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
       // Optimized method since we know that 'n & (n-1)' will drop the lowest 1 bit so using this we can run the loop only as no. of time as the number of set bits.
       int onebits = 0;
       while(n>0)
       {
           onebits ++;
           n = n&(n-1);
       }
        return onebits;
    }
};

// Follow up: If this function is called many times, how would you optimize it?
// Ans: We can use a lookup table to store the number of set bits in all the numbers from 0 to 2^32-1 and then we can just return the value from the table for the given number.
int main()
{
    return 0;
}