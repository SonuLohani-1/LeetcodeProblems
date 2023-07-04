#include<bits/stdc++.h>
using namespace std;
long long totalCost(vector<int>& costs, int k, int candidates) {
        // making two priority queues for both the sides'
        int n = costs.size();
        priority_queue <int, vector<int>, greater<int> > p1;
        priority_queue <int, vector<int>, greater<int> > p2;
        int ptr1 = 0;
        int ptr2 = n - 1;
        while(ptr1 < candidates && ptr2 >= n - candidates && ptr1 < ptr2)
        {
            p1.push(costs[ptr1]);
            p2.push(costs[ptr2]);
            ptr1++;
            ptr2--;
        }
        long long ans = 0;
        for(int i = 0; i < k; i++)
        {
            if(p1.top() <= p2.top())
            {
                ans += p1.top();
                p1.pop();
                if(ptr1 < n && ptr1 < ptr2);
                p1.push(costs[ptr1++]);
            }
            else
            {
                ans += p2.top();
                p2.pop();
                if(ptr2 >= 0 && ptr2 > ptr1)
                p2.push(costs[ptr2--]);
            }

        }
        return ans;

    }
int main()
{
    return 0;
}