#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 530 and 783 on Leetcode - Minimum absolute difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL) {}
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

// The idea is to do an inorder traversal of the tree and find the minimum difference between two adjacent elements
// The intuition is that the inorder traversal of a BST is a sorted array
// So, we can find the minimum difference between two adjacent elements in the sorted array
// These are the steps to solve the problem
// 1. Initialize the answer variable to INT_MAX
// 2. Initialize a pointer to the previous node to NULL
// 3. Do an inorder traversal of the tree
// 4. If the previous node is not NULL, then update the answer variable with the minimum of the current answer and the difference between the current node and the previous node
class Solution
{
public:
    int getMinimumDifference(TreeNode* root)
    {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root, prev, ans);
        return ans;
    }
    void inorder(TreeNode* root, TreeNode* &prev, int &ans)
    {
        if(root == NULL)
            return;
        inorder(root -> left, prev, ans);
        if(prev != NULL)
            ans = min(ans, root -> val - prev -> val);
        prev = root;
        inorder(root -> right, prev, ans);
    }
};
int main()
{
    return 0;
}