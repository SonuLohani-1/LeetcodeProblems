#include<bits/stdc++.h>
using namespace std;
// This is the solution of the majority element problem on leetcode
class Solution
{
    public:
    int majorityElement(vector<int> &nums)
    {
        // The logic for the above solution is that the majority element will always be greater than the half of the size of the array.
        int count = 0;
        int candidate = 0;
        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            if (num == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};
int main()
{
    return 0;
}