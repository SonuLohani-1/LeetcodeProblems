#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 124 on leetcode - Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

// We will use a recursive approach to solve this problem
// The logic is that we will find the maximum path sum for the left and right subtree
// and then we will add the current node value to it
// and then we will check if the current node value is greater than the sum of the left and right subtree
// if it is greater then we will update the maximum path sum
// and then we will return the maximum path sum of the current node
// and we will do this recursively for all the nodes
// and at the end we will return the maximum path sum
// Time Complexity - O(n)
// Space Complexity - O(n)


int main()
{
    return 0;
}