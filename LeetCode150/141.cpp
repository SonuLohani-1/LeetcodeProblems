#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 141. Linked List Cycle in LeetCode
// https://leetcode.com/problems/linked-list-cycle/

// The idea is to use two pointers, one slow and one fast. The slow pointer moves one step at a time while the fast pointer moves two steps at a time. If the fast pointer reaches the end of the list then there is no cycle. If the fast pointer meets the slow pointer then there is a cycle.

// Time complexity: O(n)
// Space complexity: O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL) {
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
int main()
{
    return 0;
}