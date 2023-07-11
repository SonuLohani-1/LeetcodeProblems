#include<bits/stdc++.h>
using namespace std;
int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> u;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            u[nums[i]]++;
        }
        for(auto it : u)
        {
            if(it.first == k - it.first)
            {
                ans+=it.second/2;
            }
            else if(u[k-it.first])
            {
                ans += min(it.second, u[k-it.first]);
                u[k-it.first] = 0;
            }
           
        }
        return ans;
    }
int main()
{
    vector<int> nums = 
    {
        29,26,81,70,75,4,48,38,22,10,51,62,17,50,7,7,24,61,54,44,30,29,66,83,6,45,24,49,42,31,10,6,88,48,34,10,54,56,80,41,19
    };
    cout << maxOperations(nums, 12) << endl;
    return 0;
}