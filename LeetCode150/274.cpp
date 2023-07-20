#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 274 on leetcode H-Index
// https://leetcode.com/problems/h-index/

// The intuition for this problem is that we can sort the array and then we can find the h-index
// by traversing the array and finding the maximum value of h-index
// The time complexity of this solution is O(nlogn) and space complexity is O(1)
class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;
        for(int i = 0; i < n; i++)
        {
            // at every index we can have the same h index or the h index can be the minimum of the number of citations or current paper and the number of papers left to check which is n - i
            h = max(h, min(citations[i], n - i));
        }
        return h;
    }
};

// The more time efficient solution is to use counting sort
// The time complexity of this solution is O(n) and space complexity is O(n)
// since the h-index can be atmost n we can use a vector of size n + 1 to store the count of the number of papers with citations i and for citation greater than n we can store the count in the n index
class Solution 
{
    public:
    int hIndex(vector<int>& citations) 
    {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            if(citations[i] >= n)
            {
                count[n]++;
            }
            else
            {
                count[citations[i]]++;
            }
        }
        int sum = 0;
        for(int i = n; i >= 0; i--)
        {
            sum += count[i];
            if(sum >= i)
            {
                return i;
            }
        }
        return 0;
    }

};
int main()
{
    return 0;
}