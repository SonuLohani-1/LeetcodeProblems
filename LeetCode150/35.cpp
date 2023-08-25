#include<iostream>
using namespace std;
// This is the solution of the problem 35 on leetcode - Search Insert Position
// https://leetcode.com/problems/search-insert-position/

// We can use binary search to find the index of the target element in the array.
// If the target element is not present in the array then we can find the index of the element which is just greater than the target element.
// If the target element is present in the array then we can find the index of the target element.  

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};
int main()
{
    return 0;
}