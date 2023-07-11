#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool MySearch(vector<vector<int>> &matrix, int target, int x1, int x2)
    {
        if(x2 - x1 == 1 || x2 == x1)
        {
            for(int i = x1; i <= x2; i++)
            {
                int left = 0;
                int right = matrix[0].size() - 1;
                // do the simple linear binary search
                while(left <= right)
                {
                    int mid = (left + right)/2; // ranges are not very high therefor this version
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] > target) right = mid - 1;
                    else left = mid + 1;
                }
            }
            return false;
        }
        // here basically it boils down to first we apply binary search in the rows and then in column
        // therefore we get the time complexity of O(log m + log n) = O(log m*n)
        int mid_x = (x1 + x2)/2;
        if(matrix[mid_x][0] == target) return true;
        else if(matrix[mid_x][0] > target) 
        return MySearch(matrix, target, x1, mid_x-1);

        return MySearch(matrix, target, mid_x, x2);

    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        return MySearch(matrix, target, 0, row - 1);
    }
};
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 1;
    Solution solution;
    int ans = solution.searchMatrix(matrix, target);
    cout << ans << endl;
    return 0;
}