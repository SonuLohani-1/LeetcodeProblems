#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums [right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[right];
    }
};
int main()
{
    vector<int>  nums = {3,4,5, 6, 7 ,-1 ,-2, 0, 4, 5};
    Solution solution;
    int ans = solution.findMin(nums);
    cout << ans << endl;
    return 0;
}