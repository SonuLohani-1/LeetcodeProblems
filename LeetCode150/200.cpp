#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
int row;
int col;
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
int main()
{
    Solution solution;

    return 0;
}