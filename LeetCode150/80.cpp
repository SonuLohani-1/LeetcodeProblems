#include <bits/stdc++.h>
using namespace std;
// This is the soluution of the problem remove duplicates from sorted array II on leetcode
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (i < 2 || nums[j] > nums[i - 2])
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

// This is my version of the solution
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();
        int j = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[j - 1] || (nums[i] == nums[j - 1] && nums[i] != nums[j - 2]))
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
int main()
{
    return 0;
}