#include <bits/stdc++.h>
using namespace std;

// This is the solution of the problem 48 on leetcode Rotate Image
// https://leetcode.com/problems/rotate-image/

// The intuition behind this problem is to first transpose the matrix and then
// reverse each row of the matrix. This will give us the rotated matrix.

// This is my actual solution which I submitted in Leetcode
class Solution
{
public:
    // function to get the transpose of a matrix
    void transpose(vector<vector<int>> &matrix)
    {
        // this functiion works only for a square matrix
        int n = matrix.size();
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < row; col++)
            {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }
    }

    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        int n = matrix.size();
        while (n--)
        {
            reverse(matrix[n].begin(), matrix[n].end());
        }
    }
};

// There is also another solution to this problem which is to rotate the matrix
// in a group of four elements.
// This is a bit tricky but the main idea behind this problem is
// to rotate the matrix in a group of four elements.

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            for (int j = 0; j < right - left; j++)
            {
                int top = left;
                int bottom = right;

                // Save the top left element
                int temp = matrix[top][left + j];

                // Move the bottom left element to the top left
                matrix[top][left + j] = matrix[bottom - j][left];

                // Move the bottom right element to the bottom left
                matrix[bottom - j][left] = matrix[bottom][right - j];

                // Move the top right element to the bottom right
                matrix[bottom][right - j] = matrix[top + j][right];

                // Move the top left element to the top right
                matrix[top + j][right] = temp;
            }
            left++;
            right--;
        }
    }
};

int main()
{
    return 0;
}