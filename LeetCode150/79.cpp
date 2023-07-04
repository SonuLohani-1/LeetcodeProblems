#include <bits/stdc++.h>
using namespace std;
// This is the word search problem I am trying to solve here
// for searching word if some square has already been visited
class Solution
{
private:
    bool search(vector<vector<char>> &board, string &word, int i, int j, int m, int n, vector<vector<bool>> &traversal, int idx)
    {
        if(idx == word.length()) return true;
        if(i < 0 || j < 0 || i == m || j == n) return false;
        if(traversal[i][j] || board[i][j] != word[idx]) return false;

        traversal[i][j] = true;
        // searching left;
        bool a = search(board, word, i, j-1, m, n, traversal, idx+1) ||
                search(board, word, i, j+1, m, n, traversal, idx+1)||
                search(board, word, i-1, j, m, n, traversal, idx+1)||
                search(board, word, i+1, j, m, n, traversal, idx+1);
        
        
        traversal[i][j] = false;
        return a;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> traversal(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (board[i][j] == word[0])
                {
                    if (search(board, word, i, j, m, n, traversal, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> board = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    string word = "AAAAAAAAAAAAAAB";
    cout << solution.exist(board, word) << endl;
    return 0;
}