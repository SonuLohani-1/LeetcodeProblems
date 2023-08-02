#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 146. LRU Cache in Leetcode   
// https://leetcode.com/problems/lru-cache/

// The idea is to use a doubly linked list and a hashmap.
// The doubly linked list will store the key and value of the node.
// The hashmap will store the key and the pointer to the node.
// When we access a node, we move it to the front of the list.
// When we add a node, we add it to the front of the list.
// When we remove a node, we remove it from the end of the list.
// Time Complexity: O(1)
// Space Complexity: O(n)

// This is my actual Solution:

// Definition for doubly-linked list.
struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr){}
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> dict;

    // this head and tail are sentinals for making our work easy
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(dict.find(key) == dict.end()) // means the key was not there
        {
            return -1;
        }

        Node *node = dict[key];
        remove(node);// remove the node from the old position in list
        add(node); // adds the node at the last postion
        return node->val;
    }
    
    void put(int key, int value) {
        if(dict.find(key) != dict.end()) // key is already present first remove it before inserting 
        {
            Node *oldNode = dict[key];
            remove(oldNode);
        }
        Node *node = new Node(key, value);
        dict[key] = node;
        add(node);
    
        if(dict.size() > capacity) // check if the insertion has crossed the capacity
        {
            Node *nodeToDelete = head->next;
            remove(nodeToDelete);
            dict.erase(nodeToDelete->key);
        }  
    }

    void add(Node *node)
    {
        Node *previousEnd = tail->prev;
        previousEnd->next = node;
        node->prev = previousEnd;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

// This is the solution using inbuilt list and unordered_map
// The function used are splice, erase, push_front, pop_back

// splice function is used to move the node to the front of the list
// splice function takes 3 arguments, the iterator to the position where we want to move the node, the list from which we want to move the node, the iterator to the node which we want to move

// erase function is used to remove the node from the list
// erase function takes 1 argument, the iterator to the node which we want to remove

// push_front function is used to add the node to the front of the list

// pop_back function is used to remove the node from the end of the list

// Time Complexity: O(1)
// Space Complexity: O(n)
class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        l.splice(l.begin(), l, m[key]);
        return m[key]->second;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            l.splice(l.begin(), l, m[key]);
            m[key]->second = value;
            return;
        }
        if (l.size() == capacity)
        {
            int k = l.back().first;
            l.pop_back();
            m.erase(k);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};
int main()
{
    return 0;
}