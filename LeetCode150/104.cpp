#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 104. Maximum Depth of Binary Tree in Leetcode
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// This is a simple recursive solution.
// Time Complexity: O(n)
// Space Complexity: O(n) because of the recursion stack

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// This is an iterative solution using BFS.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            int size = q.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }
        }
        return depth;
    }
};

int main()
{
    return 0;
}