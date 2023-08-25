#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 69 on leetcode - sqrt(x)
// https://leetcode.com/problems/sqrtx/

// The solution is to use binary search to find the square root of the number
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int low = 1;
        int high = x;
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(mid <= x/mid)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}