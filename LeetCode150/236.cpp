#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 236 on leetcode - Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode() : val(0), left(NULL), right(NULL) {}
    
    TreeNode(int _val) : val(_val), left(NULL), right(NULL) {}
    
    TreeNode(int _val, TreeNode* _left, TreeNode* _right)
    : val(_val), left(_left), right(_right) {}
};

//The method is to use recursion
// If we find the node p or q, then we return that node
// If we find both the nodes in the left subtree, then we return the left subtree
// If we find both the nodes in the right subtree, then we return the right subtree
// If we find one node in the left subtree and the other node in the right subtree, then we return the root
// Time complexity - O(n)
// Space complexity - O(n) // Space complexity is coming out to be O(n) because of the recursive stack

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root)
        {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p ,q);
        
        if(left != NULL && right != NULL)
        {
            return root;
        }
        
        if(left != NULL)
        {
            return left;
        }
        
        return right;
    }
};

int main()
{
    return 0;
}