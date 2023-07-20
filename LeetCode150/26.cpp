#include <bits/stdc++.h>
using namespace std;
// This is the solution of problem remove duplicate from sorted array on leetcode
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};
int main()
{
    return 0;
}