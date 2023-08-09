#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 200 on leetcode- Number of Islands
// https://leetcode.com/problems/number-of-islands/

// The idea is to do a DFS on the grid and mark all the connected 1's as 0's.
// The number of times we do a DFS is the number of islands.
// Time complexity: O(m*n)
// Space complexity: O(m*n) because of the recursion stack
class Solution {
private:
int row;
int col;

// markConnected is nothing but a DFS
void markConnected(vector<vector<char>>& grid, int i, int j){
    if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') return;

    grid[i][j] = '0';
    //marking vertically up
    markConnected(grid, i-1, j);
    // marking vertically down
    markConnected(grid, i+1, j);
    // marking horizontally left
    markConnected(grid, i, j-1);
    //marking horizontally right;
    markConnected(grid, i, j+1);
    return;
}
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int numIslands = 0;
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                if(grid[i][j] == '1')
                {
                    numIslands++;
                    markConnected(grid, i, j);
                }
            }
        }
        return numIslands;
    }
};

// The other way to solve this problem is to use disjoint set union.
// The disjoint set union is a data structure that keeps track of a set of elements partitioned into a number of disjoint subsets.
// The idea is to iterate over the grid and if we find a 1, we union it with its adjacent 1's.
// The number of disjoint sets is the number of islands.
// Time complexity: O(m*n)
// Space complexity: O(m*n)

class Solution {
private:
int row;
int col;
public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int numIslands = 0;
        vector<int> parent(row*col, -1);
        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                if(grid[i][j] == '1')
                {
                    numIslands++;
                    parent[i*col + j] = i*col + j;
                    if(i > 0 && grid[i-1][j] == '1') unionSet(parent, i*col + j, (i-1)*col + j);
                    if(i < row-1 && grid[i+1][j] == '1') unionSet(parent, i*col + j, (i+1)*col + j);
                    if(j > 0 && grid[i][j-1] == '1') unionSet(parent, i*col + j, i*col + j-1);
                    if(j < col-1 && grid[i][j+1] == '1') unionSet(parent, i*col + j, i*col + j+1);
                }
            }
        }
        return numIslands;
    }
    
    int findSet(vector<int> &parent, int i) {
        if(parent[i] == i) return i;
        return parent[i] = findSet(parent, parent[i]);
    }
    
    void unionSet(vector<int> &parent, int i, int j) {
        int parent_i = findSet(parent, i);
        int parent_j = findSet(parent, j);
        if(parent_i != parent_j) parent[parent_i] = parent_j;
        return;
    }
};
int main()
{
    Solution solution;

    return 0;
}