#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 114 on leetcode - Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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

// This is my first approach to the problem
// Recursive approach
// Time complexity - O(n)
// Space complexity - O(n) // Space complexity is coming out to be O(n) because of the recursive stack
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;


        root->left = NULL;
        if(left == NULL) return;

        root->right = left;
        while(left->right != NULL)
        {
            left = left->right;
        }

        left->right = right;
    }
};

// The follow up question is to solve the problem in O(1) space complexity
// For O(1) space complexity, we can use Morris Traversal
// Morris Traversal algorithm is used to traverse the tree without using any extra space
// Time complexity - O(n)
// Space complexity - O(1)

// In this method first we start with the root node
// If the root node has a left child, then we find the inorder predecessor of the root node
// Inorder predecessor is the rightmost node in the left subtree of the root node
// We connect the inorder predecessor to the right child of the root node
// Then we make the left child of the root node as the right child of the root node
// Then we make the left child of the root node as NULL
// Then we move to the right child of the root node
// If the root node does not have a left child, then we move to the right child of the root node
// We repeat the above steps until we reach the end of the tree

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }

        TreeNode* curr = root;
        while(curr != NULL)
        {
            if(curr->left != NULL)
            {
                TreeNode* prev = curr->left;
                while(prev->right != NULL)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
int main()
{
    return 0;
}