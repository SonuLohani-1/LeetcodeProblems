#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 70 on leetcode - Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

// The solution is to use fibonacci series
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int first = 1;
        int second = 2;
        for(int i = 3; i<=n; i++)
        {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

int main()
{
    return 0;
}