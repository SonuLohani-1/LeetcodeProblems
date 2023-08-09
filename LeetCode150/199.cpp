#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 199 on Leetcode - Right side view of a binary tree
// https://leetcode.com/problems/binary-tree-right-side-view/

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

// The idea is to do a level order traversal of the tree and print the last element of each level
class Solution
{
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(i == n - 1)
                    ans.push_back(temp -> val);
                if(temp -> left != NULL)
                    q.push(temp -> left);
                if(temp -> right != NULL)
                    q.push(temp -> right);
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}