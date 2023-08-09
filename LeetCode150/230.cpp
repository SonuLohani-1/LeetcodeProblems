#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 230 on leetcode-kth-smallest-element-in-a-bst
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// The idea is to do an inorder traversal of the tree and keep a count of the number of nodes visited so far.
// When the count reaches k, we stop the traversal and return the answer.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        inorder(root, k, count, ans);
        return ans;
    }
    
    void inorder(TreeNode* root, int k, int &count, int &ans) {
        if(root == NULL) return;
        inorder(root->left, k, count, ans);
        count++;
        if(count == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, count, ans);
    }
};
int main()
{
    return 0;
}