#include<bits/stdc++.h>
using namespace std;

// This is the definition of the tree node:
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};
// This is the solution of the problem 106 on leetcode - construct binary tree from inorder and postorder traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

// The idea is to use the postorder array to find the root of the tree and then use the inorder array to find the left and right subtree of the root
// For faster search in the inorder array we can use a hashmap to store the index of the elements of the inorder array
// Time complexity - O(n)
// Space complexity - O(n)

// This is my first solution
class Solution {
    int currIdx = 0;
    unordered_map<int, int> indexMap; // Map to store indices of inorder elements

    TreeNode* f(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;
        if (currIdx < 0) return nullptr;

        TreeNode* currRoot = new TreeNode(postorder[currIdx]);
        int currElementIdx = indexMap[postorder[currIdx--]];
        currRoot->right = f(inorder, postorder, currElementIdx + 1, right);
        currRoot->left = f(inorder, postorder, left, currElementIdx - 1);
        return currRoot;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        currIdx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i; // Store indices of inorder elements in the map
        }
        return f(inorder, postorder, 0, inorder.size() - 1);
    }
};

// This is more general solution
class Solution {
    public:
        unordered_map<int, int> mp;
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            for(int i = 0; i < inorder.size(); i++) {
                mp[inorder[i]] = i;
            }
            return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
        }
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
            if(inStart > inEnd || postStart > postEnd) return NULL;
            TreeNode* root = new TreeNode(postorder[postEnd]);
            int rootIndex = mp[root->val];
            int leftSubtreeSize = rootIndex - inStart;
            root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSubtreeSize - 1);
            root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);
            return root;
        }
};
int main()
{
    return 0;
}