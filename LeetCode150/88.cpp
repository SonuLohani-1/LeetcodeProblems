#include<bits/stdc++.h>
using namespace std;
// This is the soluution of the problem merge sorted array in leetcode
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // Making two pointers for both the array.
        int a = m -1;
        int b = n -1;
        // making an end pointer for inserting the element in nums1
        int end = m+n - 1;
        while(a >= 0 && b >= 0)
        {
           if(nums1[a] >= nums2[b])
           {
               nums1[end] = nums1[a];
               a--;
           }
            else
            {
                nums1[end] = nums2[b];
                b--;
            }
            end--;
        }
        
       while(b >= 0)
           {
               nums1[end] = nums2[b];
               b--;
               end--;
           }

}
};


int main()
{
    return 0;
}