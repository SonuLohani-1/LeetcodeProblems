#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int i = n-2; i>=0; i--)
        {
            if(i + nums[i] >= n-1)
            {
                dp[i] = 1;
                continue;
            }

            for(int j = 1; j <= nums[i]; j++)
            {
               int stepFromHere = dp[i+j];

               if(stepFromHere != INT_MAX)
               dp[i] = min(stepFromHere + 1, dp[i]);
            }
        }
        return dp[0];
    }
int main()
{
    vector<int> nums = {2,3,1,1,4};
    cout << jump(nums, 0) << endl;
    return 0;
}