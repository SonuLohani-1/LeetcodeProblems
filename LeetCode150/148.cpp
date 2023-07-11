#include <bits/stdc++.h>
using namespace std;
// definition of singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *construct_list(vector<int> arr)
{
    if (arr.size() == 0)
        return 0;

    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

class Solution
{
private:
    ListNode *mergeSortedLists(ListNode *head1, ListNode *head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        ListNode *dummy = new ListNode(INT_MAX);
        ListNode *traversalPtr = dummy;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val > head2->val)
            {
                traversalPtr->next = head2;
                head2 = head2->next;
                traversalPtr = traversalPtr->next;
            }
            else
            {
                traversalPtr->next = head1;
                head1 = head1->next;
                traversalPtr = traversalPtr->next;
            }
        }
        while (head1 != NULL)
        {
            traversalPtr->next = head1;
            head1 = head1->next;
            traversalPtr = traversalPtr->next;
        }
        while (head2 != NULL)
        {
            traversalPtr->next = head2;
            head2 = head2->next;
            traversalPtr = traversalPtr->next;
        }
        traversalPtr->next = NULL;
        return dummy->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        // here I am trying to use the merge sort techinique
        // we can simply traverse to the middle so I am using Flloyd's algorithm
        // to get to the middle node

        if (head == NULL || head->next == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *beforeSlow = head;
        while (fast != NULL && fast->next != NULL)
        {
            beforeSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        beforeSlow->next = NULL;
        ListNode *head1 = sortList(head);
        ListNode *head2 = sortList(slow);
        return mergeSortedLists(head1, head2);
    }
};
int main()
{
    vector<int> arr = {4, 2, 1, 3};
    ListNode *head = construct_list(arr);
    Solution solution;
    head = solution.sortList(head);
    while(head != NULL)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}