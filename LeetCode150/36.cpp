#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem valid Sudoku on leetcode
// https://leetcode.com/problems/valid-sudoku/

// The idea is to use a hash map to store the number of times a number appears in a row, column or a box
// If the number appears more than once then the sudoku is not valid
// For checking the box we use the formula (i/3)*3 + j/3 to get the box index
// from this formula first 3 horizontal boxes will have index 0,1,2, next 3 will have 3,4,5 and last 3 will have 6,7,8
// Time complexity:- O(1)
// Space complexity:- O(1)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,int> row[9],col[9],box[9];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j]-'0';
                    int box_index = (i/3)*3 + j/3;
                    row[i][num]++;
                    col[j][num]++;
                    box[box_index][num]++;
                    if(row[i][num]>1 || col[j][num]>1 || box[box_index][num]>1)
                        return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
