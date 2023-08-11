#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 25 on leetcode - Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

// Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
    ListNode(int x, ListNode *next)
    {
        val = x;
        this->next = next;
    }
};


// This is my first solution using stack
// Time Complexity - O(n)
// Space Complexity - O(k) where k is the size of the stack
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        temp = head;

        stack<ListNode*> st;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp2 = dummy;
        while(temp != NULL )
        {
            st.push(temp);
            temp = temp->next;
            if(st.size() == k)
            {
                
                while(!st.empty())
                {
                    dummy->next = st.top();
                    st.pop();
                    dummy = dummy->next;
                }
                dummy->next = temp;
            }
        }
        return temp2->next;
    }
};
int main()
{
    return 0;
}