#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 100 on leetcode - same tree
// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)  return true;
        if(p == NULL || q == NULL)  return false;
        if(p->val != q->val)    return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
int main()
{
    return 0;
}