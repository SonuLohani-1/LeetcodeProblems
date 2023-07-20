#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem ZigZag Conversion on leetcode.
// https://leetcode.com/problems/zigzag-conversion/

// The intuition for solving this problem is that we can use a vector of strings to store the characters in zigzag order.
// we traverse the string for each row and then add elements to each row and then again run a for loop and add elements to each row except the first and the last row.

/*
P     I    N // v[0]
A   L S  I G // v[1]
Y A   H R    // v[2]
P     I      // v[3]
*/
// The time complexity is O(n) and the space complexity is O(n).
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string> v(numRows);
        int n = s.length();
        int i = 0;
        while(i < n)
        {
            for(int j = 0; j < numRows && i < n; j++)
                v[j] += s[i++];
            for(int j = numRows-2; j > 0 && i < n; j--)
                v[j] += s[i++];
        }
        string ans;
        for(int i = 0; i < numRows; i++)
            ans += v[i];
        return ans;
    }
};

// We can also solve it without using any extra space.
// The time complexity is O(n) and the space complexity is O(1).
// step by step explanation of the solution is as follows:
// 1. We can observe that the characters in the first row are at an interval of 2*(numRows-1).
// 2. The characters in the last row are also at an interval of 2*(numRows-1).
// 3. The characters in the middle rows are at an interval of 2*(numRows-1) - 2*i and one more element will come at for let's say ith row will come at (numRows - 1)  - i - 1 + (numRows - 1) = 2*(numRows - 1) - 2*i. with k as the index for the that element we hwill have next element at 2 * (numRow - 1) - 2*i + k.
// 4. We can use these intervals to find the characters in the zigzag order.

class Solution2 {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int n = s.length();
        string ans;
        int cycle = 2*numRows - 2;
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j+i < n; j += cycle)
            {
                ans += s[j+i];

                // since current index is i + j next element will be at cycle - 2*i + (i + j) = cycle - i + j.
                if(i != 0 && i != numRows-1 && j+cycle-i < n)
                    ans += s[j+cycle-i];
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}