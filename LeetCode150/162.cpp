#include<iostream>
#include<vector>
using namespace std;
// This is the solution of the problem 162 on leetcode - Find Peak Element
// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Iterative binary search solution
        // mid element is greater than it right element than there should be atleast one peak in first half 
        // similarly if mid <= right element than there should be at least one peak in the the other half;
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(nums[mid] > nums[mid+1])
                r = mid; // not mid +1 since mid can also be peak
            else
                l = mid + 1; // no chance of mid begin peak element
        }
        return l;
    }
};
int main()
{
    return 0;
}