#include <bits/stdc++.h>
using namespace std;
vector<string> summaryRanges(vector<int> &nums)
{
    if(nums.size() == 0) return {};
    if(nums.size() == 1) return {to_string(nums[0])};
    int lower_bound = nums[0];
    int upper_bound;
    vector<string> ans;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] != nums[i-1]+1)
        {
            upper_bound = nums[i-1];
            if(lower_bound == upper_bound) ans.push_back(to_string(lower_bound));
            else ans.push_back(to_string(lower_bound) + "->" + to_string(upper_bound));
            lower_bound = nums[i];
        }
    }
    if(upper_bound != nums[nums.size()-1])
    {
        upper_bound = nums[nums.size()-1];
        if(upper_bound == lower_bound)
            ans.push_back(to_string(lower_bound));
        else
            ans.push_back(to_string(lower_bound) + "->" + to_string(upper_bound));
    }
    return ans;
}
int main()
{
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> ranges = summaryRanges(nums);
    for(auto it : ranges)
    {
        cout << it << endl;
    }
    return 0;
}