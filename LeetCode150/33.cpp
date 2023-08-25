#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 33 on leetcode - Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// The idea behind this problem is to find the pivot element in the array.
// The pivot element is the element which is smaller than its previous element.
// After finding the pivot element we can divide the array into two parts.
// The first part will be from start to pivot and the second part will be from pivot + 1 to end.
// Now we can apply binary search on both the parts to find the target element.

// Since the array is sorted before and after the pivot:
// so first find the pivot element 
// and then use the binary search in the first half and the second half

class Solution {
private:
    int find_pivot(vector<int>& nums)
    {
        if (nums.size() == 1) return 0;
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            if(mid == nums.size()-1) return 0;
            //if mid element is greater than its next element than mid is the pivot element
            if(nums[mid] > nums[mid+1]) return mid;

            // if mid element is smaller than start element then the pivot element lies in the first half
            else if(nums[mid] < nums[start]) end = mid - 1;

            // else if the mid element is greater than start element then the pivot element lies in the second half
            else start = mid + 1;
        }
        return -1;
    }

    int binary_search(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = (right - left)/2 + left;

            if(nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {

        int pivot = find_pivot(nums);
        int a = binary_search(nums, target, 0, pivot);
        int b = binary_search(nums, target, pivot+1, nums.size()-1);

        return a != -1 ? a : b;
    }
};
int main()
{
    return 0;
}