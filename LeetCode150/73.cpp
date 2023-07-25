#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 73 on leetcode Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

// The intuition behind this problem is to use the first row and first column
// of the matrix as a flag to indicate whether a row or column has to be set to
// zero or not.
// We can then traverse all row and column and set the elements to zero in first row and first column
// if the element in that row or column is zero.

class Solution
{
    public:
        void setZeroes(vector<vector<int>> &matrix)
        {
            int rows = matrix.size(), cols = matrix[0].size();
            bool first_row = false, first_col = false;
            for (int i = 0; i < rows; i++)
            {
                if (matrix[i][0] == 0)
                {
                    first_col = true;
                    break;
                }
            }
            for (int i = 0; i < cols; i++)
            {
                if (matrix[0][i] == 0)
                {
                    first_row = true;
                    break;
                }
            }
            for (int i = 1; i < rows; i++)
            {
                for (int j = 1; j < cols; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for (int i = 1; i < rows; i++)
            {
                for (int j = 1; j < cols; j++)
                {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }
            if (first_row)
            {
                for (int i = 0; i < cols; i++)
                    matrix[0][i] = 0;
            }
            if (first_col)
            {
                for (int i = 0; i < rows; i++)
                    matrix[i][0] = 0;
            }
        }
};
int main()
{
    return 0;
}