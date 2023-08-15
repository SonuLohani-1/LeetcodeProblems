#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 211 on leetcode - Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

// The idea is to use a Trie data structure to store the words and then search for the words using DFS.
// The only difference between this problem and the problem 208 is that we have to search for the words
// using DFS. We can do this by using a helper function that takes the current node and the current index
// of the word we are searching for. If the current index is equal to the length of the word, then we check
// if the current node is the end of the word. If it is, then we return true, else we return false. If the
// current index is not equal to the length of the word, then we check if the current character is a '.'.
// If it is, then we check if any of the children of the current node is not NULL. If it is, then we call
// the helper function recursively with the current node and the current index + 1. If the current character
// is not a '.', then we check if the current character is present in the children of the current node. If it
// is, then we call the helper function recursively with the current node and the current index + 1. If the
// current character is not present in the children of the current node, then we return false.

// making a TrieNode class
class TrieNode{
    public:
        vector<TrieNode*> children;
        bool isEnd;
    
        TrieNode(){
            children = vector<TrieNode*>(26, 0);
            isEnd = false;
        }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (auto c : word)
        {
            if(curr->children[c-'a'] == NULL)
            {
                curr->children[c-'a'] = new TrieNode();
            }
            
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(0, word, root);
    }

    bool dfs(int i, string word, TrieNode* root)
    {
        if(root == NULL) return false;
        if(i == word.length()) return root->isEnd;
        TrieNode* curr = root;
        for(int j = i; j < word.length(); j++)
        {
            if(word[j] == '.')
            {
                for(int k = 0; k < 26; k++)
                {
                    if(curr->children[k] != NULL && dfs(j+1, word, curr->children[k]))
                        return true;
                }
                return false;
            }
            else
            {
                if(curr->children[word[j] - 'a'] == NULL) return false;
                curr = curr->children[word[j] - 'a'];
            }
        }

        return curr!=NULL && curr->isEnd;
    }
};
int main()
{
    return 0;
}