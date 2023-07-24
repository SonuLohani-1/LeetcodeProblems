#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem Container With Most Water in LeetCode
// https://leetcode.com/problems/container-with-most-water/

// The logic is to use two pointers, one from the start and one from the end
// and check if the area formed by the two pointers is greater than the maximum area or not
// if it is greater than the maximum area then update the maximum area
// if the height of the start pointer is greater than the height of the end pointer then decrement the end pointer
// else increment the start pointer
// if the start pointer is greater than the end pointer then return the maximum area

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxArea = 0;
        while(i < j)
        {
            maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        return maxArea;
    }
};
int main()
{
    return 0;
}