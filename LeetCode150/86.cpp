#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 86. Partition List in Leetcode
// https://leetcode.com/problems/partition-list/

// The idea is to use two pointers, one for the nodes with value less than x and one for the nodes with value greater than or equal to x.
// Then we connect the two lists.
// Time Complexity: O(n)
// Space Complexity: O(1)


// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* after = new ListNode(0);
        ListNode* beforeHead = before;
        ListNode* afterHead = after;
        while(head != NULL){
            if(head->val < x){
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = afterHead->next;
        return beforeHead->next;
    }
};
int main()
{
    return 0;
}