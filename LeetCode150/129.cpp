#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 129 on leetcode - Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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

// The idea is to use preorder traversal and keep on adding the value of the node to the sum
// If we are at a leaf node, then we return the sum
// Time complexity - O(n)
// Space complexity - O(n) // Space complexity is coming out to be O(n) because of the recursive stack

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    
    int helper(TreeNode* root, int sum)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return sum*10 + root->val;
        }
        
        return helper(root->left, sum*10 + root->val) + helper(root->right, sum*10 + root->val);
    }
};
int main()
{
    return 0;
}