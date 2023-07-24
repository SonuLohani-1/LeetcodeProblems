#include <bits/stdc++.h>
using namespace std;
// This is the solution of the problem 54. Spiral Matrix in Leetcode
// https://leetcode.com/problems/spiral-matrix/

// The intuition behind this problem is to keep track of the four directions
// and the boundaries of the matrix. We can use four variables to keep track

// This is my actual solution which I submitted in Leetcode
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int up_boundary = 0;
        int down_boundary = matrix.size() - 1;
        int left_boundary = 0;
        int right_boundary = matrix[0].size() - 1;
        vector<int> ans;
        int curr_row = 0, curr_col = 0;
        bool right = true, down = false, left = false, up = false;
        while (ans.size() < rows * cols)
        {
            if (right)
            {
                while (curr_col <= right_boundary)
                    ans.push_back(matrix[curr_row][curr_col++]);
                up_boundary++; // we don't need to traverse the first row again
                curr_col--;
                curr_row++;
                right = false;
                down = true;
            }
            else if (down)
            {
                while (curr_row <= down_boundary)
                    ans.push_back(matrix[curr_row++][curr_col]);

                right_boundary--; // we don't need to traverse the last col again
                curr_row--;
                curr_col--;
                down = false;
                left = true;
            }
            else if (left)
            {
                while (curr_col >= left_boundary)
                    ans.push_back(matrix[curr_row][curr_col--]);

                down_boundary--; // we don't need to traverse the last row again
                curr_row--;
                curr_col++;
                left = false;
                up = true;
            }
            else
            {
                while (curr_row >= up_boundary)
                    ans.push_back(matrix[curr_row--][curr_col]);

                left_boundary++; // we don't need to traverse the first col again
                curr_row++;
                curr_col++;
                up = false;
                right = true;
            }
        }
        return ans;
    }
};

// but there is a concise solution to this problem

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        int rows = matrix.size(), cols = matrix[0].size();
        int up_boundary = 0;
        int down_boundary = matrix.size() - 1;
        int left_boundary = 0;
        int right_boundary = matrix[0].size() - 1;
        while (ans.size() < rows * cols)
        {
            for (int i = left_boundary; i <= right_boundary && ans.size() < rows * cols; i++)
                ans.push_back(matrix[up_boundary][i]);
            up_boundary++;
            for (int i = up_boundary; i <= down_boundary && ans.size() < rows * cols; i++)
                ans.push_back(matrix[i][right_boundary]);
            right_boundary--;
            for (int i = right_boundary; i >= left_boundary && ans.size() < rows * cols; i--)
                ans.push_back(matrix[down_boundary][i]);
            down_boundary--;
            for (int i = down_boundary; i >= up_boundary && ans.size() < rows * cols; i--)
                ans.push_back(matrix[i][left_boundary]);
            left_boundary++;
        }
        return ans;
    }
};
int main()
{
    return 0;
}