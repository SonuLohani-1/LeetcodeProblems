#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem Two Sum II in LeetCode
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// The logic is to use two pointers, one from the start and one from the end
// and check if the sum of the two numbers is equal to the target or not
// if the sum is equal to the target then return the indices of the two numbers
// if the sum is greater than the target then decrement the end pointer
// if the sum is less than the target then increment the start pointer
// if the start pointer is greater than the end pointer then return an empty vector

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while(i < j)
        {
            if(numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
            else if(numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return {};
    }
};
int main()
{
    return 0;
}
