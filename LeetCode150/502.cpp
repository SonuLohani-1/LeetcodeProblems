#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 502 on leetcode - IPO
// https://leetcode.com/problems/ipo/

// First we can make pairs of profit and capital and then sort them according to the capital.
// Now we can use a priority queue to store the profits of the projects which have capital less than or equal to the current capital.
// Now we can pop the top element from the priority queue and add it to the current capital.
// We can repeat this process until we have k projects or the priority queue becomes empty.
// After this process the current capital will be the maximum capital that we can have.

// Time Complexity - O(nlogn)
// Space Complexity - O(n)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> a;
        for(int i = 0; i < profits.size(); i++)
        {
            a.push_back({capital[i], profits[i]});
        }
        sort(a.begin(), a.end());
        priority_queue<int> pq;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i].first <= w)
            {
                pq.push(a[i].second);
            }
            else
            {
                while(!pq.empty() && k && w < a[i].first)
                {
                    w += pq.top();
                    pq.pop();
                    k--;
                }
                if(w < a[i].first || k == 0) return w;
                else
                {
                    pq.push(a[i].second);
                } 
            }
        }

        while(k && !pq.empty())
        {
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};
int main()
{
    return 0;
}