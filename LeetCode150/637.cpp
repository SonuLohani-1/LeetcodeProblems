#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 637 on Leetcode - Average of levels in a binary tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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

// The idea is to do a level order traversal of the tree and print the average of each level
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp -> val;
                if(temp -> left != NULL)
                    q.push(temp -> left);
                if(temp -> right != NULL)
                    q.push(temp -> right);
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};
int main()
{
    return 0;
}