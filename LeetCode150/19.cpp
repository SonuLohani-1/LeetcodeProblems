#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 19 on leetcode- Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// The idea for this problem is to use two pointers, one fast and one slow. The fast pointer will be n steps ahead of the slow pointer. When the fast pointer reaches the end, the slow pointer will be at the node to be deleted.
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = nullptr;
        while(n--)
        {
            fast = fast->next;
        }
        while(fast)
        {
            fast = fast->next;
            if(slow == nullptr)
            {
                slow = head;
            }
            else
            {
                slow = slow->next;
            }
        }
        if(slow == nullptr)
        {
            head = head->next;
        }
        else
        {
            slow->next = slow->next->next;
        }
        return head;
    }
};
int main()
{
    return 0;
}