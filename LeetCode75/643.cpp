#include<bits/stdc++.h>
using namespace std;
int windowSum(int ptr1, int ptr2, vector<int> &nums)
{
    int currSum = 0;
    for(int i = ptr1; i <= ptr2; i++)
    {
        currSum += nums[i];
    }
    return currSum;
}


double findMaxAverage(vector<int>& nums, int k) 
{
    int ptr1 = 0;
    int ptr2 = k-1;
    double prevWindowSum = windowSum(ptr1++, ptr2++, nums);
    double maxAverage = double(prevWindowSum)/k;
    while(ptr2 < nums.size())
    {
        int currWindowSum = prevWindowSum - nums[ptr1 - 1] + nums[ptr2];
        if(maxAverage < double(currWindowSum)/k)
        maxAverage = double(currWindowSum)/k;
        prevWindowSum = currWindowSum;
        ptr1++;
        ptr2++;
    }
    return maxAverage;
}
int main()
{
    vector<int> nums = {1,12,-5,-6,50,3};
    cout << findMaxAverage(nums, 4) << endl;
    return 0;
}