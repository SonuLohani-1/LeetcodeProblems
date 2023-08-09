#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 222 on leetcode - Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/

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

// for less than O(n) time complexity, we can use binary search
// Time complexity - O(logn*logn)
// Space complexity - O(1)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        int leftHeight = 0;
        int rightHeight = 0;
        
        TreeNode* left = root;
        TreeNode* right = root;
        
        while(left != NULL)
        {
            leftHeight++;
            left = left->left;
        }
        
        while(right != NULL)
        {
            rightHeight++;
            right = right->right;
        }
        
        if(leftHeight == rightHeight)
        {
            return pow(2, leftHeight) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
int main()
{
    return 0;
}