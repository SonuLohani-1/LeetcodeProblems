#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 295 on leetcode - Find Median from Data Stream
// https://leetcode.com/problems/median-of-two-sorted-arrays/

// The logic behind this problem is to use two heaps.
// We will use one max heap and one min heap.
// The max heap will store the elements which are smaller than the median and the min heap will store the elements which are greater than the median.
// If the size of the max heap becomes greater than the size of the min heap then we will pop the top element from the max heap and push it into the min heap.
// If the size of the min heap becomes greater than the size of the max heap then we will pop the top element from the min heap and push it into the max heap.

class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_heap.empty() || num < max_heap.top())
        {
            max_heap.push(num);
        }
        else
        {
            min_heap.push(num);
        }
        if(max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size() + 1)
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if(max_heap.size() == min_heap.size())
        {
            return (max_heap.top() + min_heap.top()) / 2.0;
        }
        else if(max_heap.size() > min_heap.size())
        {
            return max_heap.top();
        }
        else
        {
            return min_heap.top();
        }
    }
};
int main()
{
    return 0;
}