#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 103 on Leetcode - Binary tree zigzag level order traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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

// The idea is to keep a variable level and if it is odd, reverse the vector
// Otherwise, very similar to 102.cpp- Binary tree level order traversal
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i++)
            {
                TreeNode* temp1 = q.front();
                q.pop();
                temp.push_back(temp1 -> val);
                if(temp1 -> left != NULL)
                    q.push(temp1 -> left);
                if(temp1 -> right != NULL)
                    q.push(temp1 -> right);
            }
            if(level % 2 == 1)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};
int main()
{
    return 0;
}