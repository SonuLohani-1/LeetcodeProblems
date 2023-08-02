#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem rotate list on leetcode
// https://leetcode.com/problems/rotate-list/

// We can first count the length of the list and then connect the tail to the head.
// Then we move the pointer to the (len - k % len)th node and cut the list.
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
private:
    int getLength(ListNode *head)
    {
        ListNode *temp = head;
        int l = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            l++;
        }
        return l;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = getLength(head);
        if (len <= 1 or k % len == 0)
            return head;

        k = k % len;

        // getting to the position of the node from where we need to detach
        ListNode *temp = head;
        for (int i = 0; i < len - k - 1; i++)
        {
            temp = temp->next;
        }

        ListNode *temp2 = temp->next;
        ListNode *newHead = temp2;
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }

        temp->next = NULL;
        temp2->next = head;
        return newHead;
    }
};

int main()
{
    return 0;
}