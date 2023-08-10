#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 133 on leetcode - Clone Graph
// https://leetcode.com/problems/clone-graph/

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// The idea is to do a bfs traversal of the graph and create a copy of each node
// and store it in a map. Then we can iterate over the map and create the edges
// of the new graph.
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        queue<Node *> q;
        q.push(node);
        unordered_map<Node *, Node *> m;
        m[node] = new Node(node->val);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            for (Node *n : curr->neighbors)
            {
                if (m.find(n) == m.end())
                {
                    m[n] = new Node(n->val);
                    q.push(n);
                }
                m[curr]->neighbors.push_back(m[n]);
            }
        }
        return m[node];
    }
};

// This is my solution which is similar to the above solution but uses dfs instead of bfs.
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        // unordered map to map new node to the old node
        unordered_map<Node *, Node *> map;
        Node *clone_node = new Node(node->val);
        map[node] = clone_node;
        dfs(node, map);
        return clone_node;
    }

    void dfs(Node *node, unordered_map<Node *, Node *> &map)
    {
        for (auto neighbor : node->neighbors)
        {
            if (map.find(neighbor) == map.end())
            {
                Node *new_node = new Node(neighbor->val);
                map[neighbor] = new_node;
                dfs(neighbor, map);
            }
            map[node]->neighbors.push_back(map[neighbor]);
        }
    }
};
int main()
{
    return 0;
}