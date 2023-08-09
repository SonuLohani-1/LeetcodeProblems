#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 98 on leetcode-validate-binary-search-tree
// https://leetcode.com/problems/validate-binary-search-tree/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// The idea to solve this problem is to do an inorder traversal of the tree and check if the nodes are in ascending order.
// If they are in ascending order, then the tree is a BST.
// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        for(int i = 1; i < v.size(); i++) {
            if(v[i] <= v[i-1]) return false;
        }
        return true;
    }
    
    void inorder(TreeNode* root, vector<int> &v) {
        if(root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

// There also exists a solution with time complexity O(n) and space complexity O(1).
// The idea is to do an inorder traversal of the tree and check if the nodes are in ascending order.
// If they are in ascending order, then the tree is a BST.
// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return inorder(root, prev);
    }
    
    bool inorder(TreeNode* root, TreeNode* &prev) {
        if(root == NULL) return true;
        if(!inorder(root->left, prev)) return false;
        if(prev != NULL && prev->val >= root->val) return false;
        prev = root;
        return inorder(root->right, prev);
    }
};

int main()
{
    return 0;
}
