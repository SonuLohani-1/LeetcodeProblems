#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 34 on leetcode - Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// The trick to solve this problem is to use binary search twice.
// First time to find the first occurence of the target element.
// Second time to find the last occurence of the target element.

class Solution {
private:
    int binary_search(vector<int>& nums, int target, bool find_first)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        int result = -1;
        while(left <= right)
        {
            mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                result = mid;
                if(find_first)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return result;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int first = binary_search(nums, target, true);
        int last = binary_search(nums, target, false);
        result.push_back(first);
        result.push_back(last);
        return result;
    }
};

// Time Complexity - O(logn)
// Space Complexity - O(1)

// This is my actual solution
class Solution {
private:
    int binary_search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid+1;
            else right = mid - 1;
        }
        return -1;
    }
    int repeated_left(vector<int>& nums, int target, int left, int right, int prev)
    {
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                prev = mid;
                right = mid-1;
            }
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return prev;
    }

    int repeated_right(vector<int>& nums, int target, int left, int right, int prev)
    {
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
            {
                prev = mid;
                left = mid + 1;
            }

            else if(target < nums[mid])
            {
                right = mid - 1;
            }

            else
            {
                left = mid + 1;
            }
        }

        return prev;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx = binary_search(nums, target);
        if(idx == -1) return {-1, -1};
        return {repeated_left(nums, target, 0, idx-1, idx), repeated_right(nums, target, idx+1, nums.size() - 1, idx)};
    }
};
int main()
{
    return 0;
}