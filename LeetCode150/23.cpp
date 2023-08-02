#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 23. merge k sorted lists on leetcode
// https://leetcode.com/problems/merge-k-sorted-lists/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {} // constructor
};

// This is my first solution 
// where I merged the lists one by one
// Time complexity: O(nk) where n is the average length of the lists and k is the number of lists

class Solution {

private:
ListNode* mergesorted(ListNode* l1 , ListNode* l2)
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++)
        {
            head = mergesorted(head, lists[i]);
        }
      return head;
    }   
};

// The other solution uses priority queue
// Time complexity: O(nlogk) where n is the average length of the lists and k is the number of lists

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // This is the declaration of the min heap (it contains the minimum element at the top)
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != NULL)
            {
                pq.push({lists[i]->val, lists[i]});
            }
        }
        ListNode* dummy = new ListNode(-100);
        ListNode* curr = dummy;
        while(!pq.empty())
        {
            pair<int, ListNode*> p = pq.top();
            pq.pop();
            curr->next = p.second;
            curr = curr->next;
            if(p.second->next != NULL)
            {
                pq.push({p.second->next->val, p.second->next});
            }
        }
        return dummy->next;
    }
};
int main()
{
    return 0;
}