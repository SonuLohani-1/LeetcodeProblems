#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 2. Add Two Numbers in LeetCode
// https://leetcode.com/problems/add-two-numbers/

// The idea is to use a dummy node to store the head of the result list. Then we iterate over the two lists and add the corresponding digits and carry. We keep adding the digits and carry until both the lists are empty and the carry is zero. We also need to take care of the case when one list is empty and the other is not.

// Time complexity: O(max(m, n))
// Space complexity: O(max(m, n))

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}
int main()
{
    return 0;
}