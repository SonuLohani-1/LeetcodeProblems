#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 138. Copy List with Random Pointer in LeetCode
// https://leetcode.com/problems/copy-list-with-random-pointer/

// The idea is to use a map to store the mapping from the original node to the new node. Then we iterate over the original list and create the new list. We also need to take care of the random pointers.
// Time complexity: O(n)
// Space complexity: O(n)

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

class Solution
{
    public:
    Node* copyRandomList(Node* head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        while (curr != NULL)
        {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != NULL)
        {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};

// we can also do it without using extra space
// The idea is to create a new node for each node in the original list and store the new node after the original node. Then we iterate over the list and set the random pointers of the new nodes. Then we separate the two lists.
int main()
{
    return 0;
}
