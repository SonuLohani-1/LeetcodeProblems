#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 173 on leetcode - Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

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

// The idea is to use inorder traversal and store the nodes in a vector
// Then we can use the vector to get the next smallest element in O(1) time
// Time complexity - O(n)
// Space complexity - O(n)

class BSTIterator {
public:
    vector<int> v;
    int index;
    
    void inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
        index = -1;
    }
    
    int next() {
        index++;
        return v[index];
    }
    
    bool hasNext() {
        if(index+1 < v.size())
        {
            return true;
        }
        
        return false;
    }
};

// We can improve the space complexity by using stack
// Time complexity - O(1)
// Space complexity - O(h) // h is the height of the tree

class BSTIterator {
public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root) {
        while(root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* curr = s.top();
        s.pop();
        
        int val = curr->val;
        
        curr = curr->right;
        
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        
        return val;
    }
    
    bool hasNext() {
        if(!s.empty())
        {
            return true;
        }
        
        return false;
    }
};
int main()
{
    return 0;
}