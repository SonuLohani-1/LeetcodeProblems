#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 127 on Leetcode - Word Ladder
// https://leetcode.com/problems/word-ladder/

// The solution is very similar to the solution of 433.cpp- Minimum Genetic Mutation
// The only difference is that here we can use any letter to mutate the word and also the length of the word need not be eight

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // maping the word list for faster access
        unordered_set<string> valid_words;
        for(auto word : wordList)
        {
            valid_words.insert(word);
        }

        // visited set to keep track of already analyzed words
        unordered_set<string> visited;

        // queue for the bfs traversal
        queue<string> q;

        q.push(beginWord);
        visited.insert(beginWord);

        // steps variable to keep track of current number of steps
        int steps = 1;

        // doing the bfs traversal
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string curr = q.front();
                q.pop();
                if(curr == endWord)
                {
                    return steps;
                }
                for(int j = 0; j < 26; j++)
                {
                    for(int k = 0; k < curr.size(); k++)
                    {
                        string transformed_word = curr;
                        transformed_word[k] = j + 'a';
                        if(!visited.count(transformed_word) && valid_words.count(transformed_word))
                        {
                            visited.insert(transformed_word);
                            q.push(transformed_word);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
int main()
{
    return 0;
}