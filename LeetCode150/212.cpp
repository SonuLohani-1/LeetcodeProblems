#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 212 on leetcode - Word Search II
// https://leetcode.com/problems/word-search-ii/

// The idea is to use a trie to store all the words and then use dfs to find the words in the board
// The time complexity is O(n*m*4^l) where n and m are the dimensions of the board and l is the length of the longest word
// The space complexity is O(n*m) for the visited array and O(n*m*4^l) for the trie

class Trie{
    public:
    vector<Trie*> children;
    string word;
    Trie(){
        children = vector<Trie*> (26, 0);
        word = "";
    }

};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // The idea is to store all the words in trie and then do dfs and as we find the words we can insert it in the ans.
        int m = board.size();
        int n = board[0].size();
        Trie* root = new Trie();
        for(auto word : words)
        {
            Trie* temp = root;
            for(auto c : word)
            {
                if(temp->children[c-'a'] == NULL)
                {
                    temp->children[c-'a'] = new Trie();
                }
                temp = temp->children[c-'a'];
            }
            temp->word = word;
        }
        vector<vector<bool>> visited(m, vector<bool> (n, 0));
        set<string> ans;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dfs(board, root, visited, ans, i, j);
            }
        }
        vector<string> res(ans.begin(), ans.end());
        return res;
    }

    void dfs(vector<vector<char>> &board, Trie* &root, vector<vector<bool>> &visited, set<string> &ans, int i, int j)
    {
        if(root == NULL) return;

        if(i < 0 || j < 0 || i == board.size() || j == board[0].size() || visited[i][j])
        return;

        visited[i][j] = true;
        if(root->children[board[i][j] - 'a'] != NULL && root->children[board[i][j] - 'a']->word != "") ans.insert(root->children[board[i][j] - 'a']->word);

        //left
        dfs(board, root->children[board[i][j] - 'a'], visited, ans, i, j-1);
        //right
        dfs(board, root->children[board[i][j] - 'a'], visited, ans, i, j+1);
        // up
        dfs(board, root->children[board[i][j] - 'a'], visited, ans, i-1, j);
        // down
        dfs(board, root->children[board[i][j] - 'a'], visited, ans, i+1, j);
        visited[i][j] = false;
    }
};
int main()
{
    return 0;
}