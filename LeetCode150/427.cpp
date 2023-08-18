#include<bits/stdc++.h>
using namespace std;

// This is the solution for the problem 427 on leetcode - Construct Quad Tree
// https://leetcode.com/problems/construct-quad-tree/

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// The idea is to use the divide and conquer technique to solve this problem
// we can divide the grid into 4 parts and then check if the top left, top right, bottom left and bottom right are all leaf nodes and have the same value
// if they are all leaf nodes and have the same value then we can return a new node with the value and isLeaf set to true
// else we can return a new node with isLeaf set to false and the top left, top right, bottom left and bottom right as the children
class Solution {
private:
    Node* constructQuadTree(vector<vector<int>>& grid, int x, int y, int size) {
        if (size == 1) {
            return new Node(grid[x][y], true);
        }
        Node* topLeft = constructQuadTree(grid, x, y, size/2);
        Node* topRight = constructQuadTree(grid, x, y + size/2, size/2);
        Node* bottomLeft = constructQuadTree(grid, x + size/2, y, size/2);
        Node* bottomRight = constructQuadTree(grid, x + size/2, y + size/2, size/2);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val) {
            return new Node(topLeft->val, true);
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructQuadTree(grid, 0, 0, grid.size());
    }
};

int main()
{
    return 0;
}