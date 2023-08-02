#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 105 on leetcode - construct binary tree from preorder and inorder traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

// This is my first solution
class Solution {
private:
    int idx = 0;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l, int r, unordered_map<int, int> &map)
    {
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = helper(preorder, inorder, l, map[root->val]-1, map);
        root->right = helper(preorder, inorder, map[root->val]+1, r, map);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // hashing the preorder element for easy access of indices
        unordered_map<int, int> map;
        for(int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }

        return helper(preorder, inorder, 0, preorder.size()-1, map);
    }
};

// This is a more general solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, mp);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& mp){
        if(preStart > preEnd || inStart > inEnd)    return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = mp[root->val];
        root->left = buildTreeHelper(preorder, inorder, preStart+1, preStart+rootIndex-inStart, inStart, rootIndex-1, mp);
        root->right = buildTreeHelper(preorder, inorder, preStart+rootIndex-inStart+1, preEnd, rootIndex+1, inEnd, mp);
        
        return root;
    }
};
int main()
{
    return 0;
}