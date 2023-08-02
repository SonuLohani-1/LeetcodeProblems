#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 82. Remove Duplicates from Sorted List II in Leetcode
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// The idea is to use two pointers, one for the current node and one for the previous node.
// If the current node is a duplicate, we skip it by changing the next pointer of the previous node.
// Otherwise, we move both pointers one step forward.

// Time Complexity: O(n)
// Space Complexity: O(1)

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;
        while (curr != NULL)
        {
            while (curr->next != NULL && prev->next->val == curr->next->val)
            {
                curr = curr->next;
            }
            if (prev->next == curr)
            {
                prev = prev->next;
            }
            else
            {
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};
int main()
{
    return 0;
}