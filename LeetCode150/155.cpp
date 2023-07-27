#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem min Stack on leetcode
// https://leetcode.com/problems/min-stack/

// This was my first approach
class MinStack {
private:
    vector<int> arr;
    vector<int> minm;
    int idx = -1;
public:
    MinStack() {
    }
    
    void push(int val) {
        arr.push_back(val);
        if(idx == -1 || minm[idx] > val)
            minm.push_back(val);
        else
            minm.push_back(minm[idx]);
        idx++;
    }
    
    void pop() {
        arr.pop_back();
        minm.pop_back();
        idx--;
    }
    
    int top() {
        return arr[idx];
    }
    
    int getMin() {
        return minm[idx];  
    }
};

// This is a same approach but but with little different writing style
// The idea is to use two stacks one for storing the elements and the other for storing the minimum element till that point
// The time complexity = O(1)
// Space complexity = O(n)
class MinStack {
private:
    vector<int> arr;
    vector<int> minm;
public:
    MinStack() {
    }
    
    void push(int val) {
        arr.push_back(val);
        if(minm.empty() || minm.back() > val)
            minm.push_back(val);
        else
            minm.push_back(minm.back());
    }
    
    void pop() {
        arr.pop_back();
        minm.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return minm.back();  
    }
};
int main()
{
    return 0;
}