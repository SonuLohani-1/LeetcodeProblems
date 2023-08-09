#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 112 on leetcode - Path Sum
// https://leetcode.com/problems/path-sum/

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

// The idea is to use preorder traversal and keep on subtracting the value of the node from the sum
// If the sum becomes 0 and we are at a leaf node, then we return true
// If the sum becomes 0 and we are not at a leaf node, then we return false
// Time complexity - O(n)
// Space complexity - O(n) // Space complexity is coming out to be O(n) because of the recursive stack

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
        {
            return false;
        }
        
        if(root->left == NULL && root->right == NULL && sum - root->val == 0)
        {
            return true;
        }
        
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main()
{
    return 0;
}