#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 215 on leetcode - Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/

// The idea behind this problem is to use the concept of min heap.
// We will create a min heap of size k and then we will push the elements of the array into the heap.
// If the size of the heap becomes greater than k then we will pop the top element from the heap.
// After pushing all the elements of the array into the heap the top element of the heap will be the kth largest element in the array.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
int main()
{
    return 0;
}