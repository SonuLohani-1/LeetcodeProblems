#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &arr, int i, bool hasJumped)
    {
        if (i >= arr.size())
            return 0;

        if (!hasJumped && arr[i] != -1)
        {
            hasJumped = true;
            i = i + arr[i];
        }
        int ans = INT_MAX;
        for (int j = 1; j <= 6; j++)
        {
            ans = min(ans, helper(arr, i + j, false));
        }
        return ans;
    }

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        // taking the board and making it 1d only
        vector<int> arr(board.size() * board.size() + 1, -1);

        // now traversing the board and filling the arr where can be jump;
        bool left = true;
        int count = 1;
        for (int i = board.size() - 1; i >= 0; i--)
        {
            if (left)
            {
                for (int j = 0; j < board.size(); j++)
                {
                    arr[count++] = board[i][j];
                }
            }
            else
            {
                for (int j = board.size() - 1; j >= 0; j--)
                {
                    arr[count++] = board[i][j];
                }
            }
            left = !left;
        }
        return helper(arr, 1, 0);
    }
};
int main()
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};

    Solution solution;
    int ans = solution.snakesAndLadders(board);
    cout << ans << endl;
    return 0;
}