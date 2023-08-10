#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 130 on leetcode - Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

// The idea is to first find all the 'O' on the boundary and then do a dfs from them
// and mark all the 'O' connected to them as '1'. Then we can simply iterate over the
// board and mark all the 'O' as 'X' and all the '1' as 'O'.

// Time Complexity - O(n*m)
// Space Complexity - O(1)

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        if(m == 0) return;
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][m-1] == 'O') dfs(board, i, m-1);
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[n-1][j] == 'O') dfs(board, n-1, j);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(board[i][j] == 'O') board[i][j] = '1';
        else return;
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
int main()
{
    return 0;
}