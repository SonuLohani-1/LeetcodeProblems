#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 108 on leetcode - Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// The idea is to use recursion to create the tree
// The time complexity is O(n) and space complexity is O(n)

// definition of the tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL){}
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
    TreeNode (int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};
class Solution
{
private:
    TreeNode* createTree(vector<int> &nums, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = createTree(nums, start, mid - 1);
        root->right = createTree(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return createTree(nums, 0, nums.size() - 1);
    }
};
int main()
{
    return 0;
}