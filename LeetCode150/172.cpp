#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 172 on Leetcode - Factorial Trailing Zeroes
// https://leetcode.com/problems/factorial-trailing-zeroes/

// The solution is to count the number of 5s in the factorial of the number because 5 * 2 = 10 and 2s are always more than 5s so we will count the number of 5s
// The number of 5s will be the number of trailing zeroes
// The observation is like number of 5s factor = number of number divisble by 5 + number of numbers divisible by 25 + number of numbers divisible by 125 and so on
// but instead of increasing the divisor we can divide the number by 5 and add it to the answer and then divide the number by 5 and so on
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n > 0)
        {
            ans += n/5;
            n /= 5;
        }
        return ans;
    }
};

// This is the first approach:
class Solution {
public:
// no. of zeroes depends on the 2's and 5's so we need to count how many 2's and 5's are there

    int trailingZeroes(int n) {
        int twos = 0;
        int fives = 0;
        for(int i = 2; i <= n; i++)
        {
            int temp = i;
            while(temp % 2 == 0)
            {
                twos++;
                temp /= 2;
            }

            temp = i;
            while(temp % 5 == 0)
            {
                fives++;
                temp /= 5;
            }
        }
        return min(twos, fives);
    }
int main()
{
    return 0;
}