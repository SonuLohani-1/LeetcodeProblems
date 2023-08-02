#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 226 on leetcode - invert binary tree
// https://leetcode.com/problems/invert-binary-tree/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)    return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        
        return root;
    }
};
int main()
{
    return 0;
}