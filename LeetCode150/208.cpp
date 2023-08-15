#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 208 on leetcode - Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/


class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        children = vector<Trie*>(26, 0);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(auto c : word)
        {
            if(curr->children[c - 'a'] == NULL)
                curr->children[c-'a'] = new Trie();
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(auto c : word)
        {
            if(curr->children[c-'a'] == NULL)
                return false;
            curr = curr->children[c-'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        auto curr = this;
        for(auto c : prefix)
        {
            if(curr->children[c-'a'] == NULL)
                return false;
            curr = curr->children[c-'a'];
        }
        return true;
    }
};


int main() {
    return 0;
}
