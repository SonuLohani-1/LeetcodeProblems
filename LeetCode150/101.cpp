#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 101 on leetcode - symmetric tree
// https://leetcode.com/problems/symmetric-tree/

// The idea is to check if the left subtree is mirror of right subtree
// and vice versa. The following two are the conditions for the same:
// 1. Their root node's key must be same
// 2. Left subtree of left subtree and right subtree of right subtree
//    must be mirror images
// 3. Right subtree of left subtree and left subtree of right subtree
//    must be mirror images

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;
        return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};

// This is an iterative solution
// The idea is to use a queue to store the nodes of the tree
// and then check if the nodes are mirror images of each other
// by popping two nodes at a time from the queue and checking
// if they are mirror images of each other
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode *root1 = q.front();
            q.pop();
            TreeNode *root2 = q.front();
            q.pop();
            if (root1 == NULL && root2 == NULL)
                continue;
            if (root1 == NULL || root2 == NULL)
                return false;
            if (root1->val != root2->val)
                return false;
            q.push(root1->left);
            q.push(root2->right);
            q.push(root1->right);
            q.push(root2->left);
        }
        return true;
    }
};
int main()
{
    return 0;
}