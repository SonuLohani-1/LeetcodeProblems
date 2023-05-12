#include<bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(auto it : m)
        {
           pq.push(make_pair(it.second, it.first));
        }
        vector<int> ans;
        for(int i = 0; i<k; i++)
        {
            pair<int, int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    } 
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2 , 3};
    int k = 3;
    vector<int> ans = topKFrequent(nums, k);
    for(auto it : ans)
    cout << it << endl;
    
    return 0;
}