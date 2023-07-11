#include <bits/stdc++.h>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
    int ptr1 = 0;
    int ptr2 = 0;
    int n = nums.size();
    int maxLen = INT_MIN;
    int zero_count = 0;
    while (ptr2 < n)
    {
        if (zero_count < k || nums[ptr1] == 1)
        {
            if (nums[ptr2] == 0)
                zero_count++;
            ptr2++;
        }
        maxLen = max(maxLen, ptr2 - ptr1);
        while (ptr1 < ptr2 && (nums[ptr1] == 0 || zero_count == k))
        {
            if (nums[ptr1] == 0)
                zero_count--;
            ptr1++;
        }
    }
    return maxLen;
}
int main()
{
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << longestOnes(nums, 3) << endl;
    return 0;
}