#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // Defining set to keep track of element
        unordered_set<string> visited;
        
        // Defining queue for bfs traversal
        queue<string> queue;

        // push the starting node in the queue and visited
        queue.push(startGene);
        visited.insert(startGene);

        // declaring a variable step to keep track of the steps
        int steps = 0;

        //BFS traversal
        while(!queue.empty())
        {
            int nodesInQueue = queue.size();
            for(int i = 0; i < nodesInQueue; i++)
            {
                string node = queue.front();
                queue.pop();

                // if we reached the end then return the current steps
                if(node == endGene)
                {
                    return steps;
                }
                
                // else doing the mutation 
                for(char c : "ACGT")
                {
                    for(int j = 0; j < node.size(); j++)
                    {
                        // doing the mutation
                        string mutant = node;
                        mutant[j] = c;

                        if(!visited.count(mutant) && find(bank.begin(), bank.end(), mutant) != bank.end())
                        {
                            queue.push(mutant);
                            visited.insert(mutant);
                        }
                    }
                }
            }

            // increasing the steps
            steps++;
        }
        return -1;
    }
};
int main()
{
    return 0;
}