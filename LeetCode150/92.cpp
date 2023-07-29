#include<bits/stdc++.h>
using namespace std;
// This is the solution of problem 92 on leetcode- Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print the linked list
void printList(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// The idea is to use 3 pointers to reverse the linked list
// We will use a dummy node to make the code more readable
// We will use a pointer to the node before the starting node of the sublist
// We will use a pointer to the starting node of the sublist
// We will use a pointer to the node after the ending node of the sublist
// We will reverse the sublist and then connect the pointers accordingly

class Solution 
{
    public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* before = dummy;
        ListNode* start = head;
        ListNode* end = head;
        for(int i = 1; i < m; i++)
        {
            before = before->next;
            start = start->next;
        }
        for(int i = 1; i < n; i++)
        {
            end = end->next;
        }
        ListNode* after = end->next;
        ListNode* prev = nullptr;
        ListNode* curr = start;
        while(curr != after)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        before->next = end;
        start->next = after;
        return dummy->next;
    }
};
int main()
{
    Solution obj;
    ListNode* head = new ListNode(1);
    ListNode* temp = head;
    for(int i = 2; i <= 5; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    printList(head);
    head = obj.reverseBetween(head, 2, 4);
    printList(head);
    return 0;
}
