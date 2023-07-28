#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 21. Merge Two Sorted Lists in LeetCode
// https://leetcode.com/problems/merge-two-sorted-lists/

// The idea is to keep a dummy node to store the head of the result list. Then we iterate over the two lists and add the smaller node to the result list. We also need to take care of the case when one list is empty and the other is not.

// Time complexity: O(m + n)
// Space complexity: O(m + n)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* l1 , ListNode* l2)
    {
        ListNode* dummy = new ListNode(-100);
        ListNode* curr = dummy;

        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                curr->next = l2;
                break;
            }
            if (l2 == NULL)
            {
                curr->next = l1;
                break;
            }
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
int main()
{
    return 0;
}