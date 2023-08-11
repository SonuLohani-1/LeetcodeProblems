#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 399 on Leetcode - Evaluate Division
// https://leetcode.com/problems/evaluate-division/

// The idea is to use the graph data structure and then use the DFS to find the path between the two nodes
// and then multiply the weights of the edges in the path to get the result
// The time complexity is O(V+E) and space complexity is O(V+E)
// Step by step explanation:
// 1. Create a graph with the given equations and values
// 2. For each query, check if the nodes are present in the graph or not
// 3. If not present, then return -1
// 4. Else, call the DFS function to find the path between the two nodes
// 5. If the path is found, then multiply the weights of the edges in the path to get the result
// 6. Else, return -1

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // This problem can be solved with the directed graph
        // first map a variable to pair of other variable and a double value
        // for e.g., a->(b, 2.0) and b->(a, 1/2.0)
        // for finding any values we can use dfs on the graph

        // making the graph
        unordered_map<string, vector<pair<string, double>>> adjacency_list;
        for(int i = 0; i < equations.size(); i++)
        {
            adjacency_list[equations[i][0]].push_back({equations[i][1], values[i]});
            adjacency_list[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        //vector for storing the ans
        vector<double> ans;

        //set to track the vis nodes in the graph
        unordered_set<string> vis;

        // finding the values of queries by calling the dfs funtion if it is not -1
        for(auto &query : queries)
        {
            if(adjacency_list.find(query[0]) == adjacency_list.end() ||
             adjacency_list.find(query[1]) == adjacency_list.end())
            {
                ans.push_back(-1.0);
            }

            else
            {
                vis.clear();
                double res = 1.0;
                if(dfs(adjacency_list, query[0], query[1], vis, res))
                    ans.push_back(res);
                else
                    ans.push_back(-1.0);
            }
        } 

        return ans;
    }

    bool dfs(unordered_map<string, vector<pair<string, double>>> &adj, string s1, string s2, unordered_set<string> &vis, double &res)
    {
        if(s1 == s2) return true;
        vis.insert(s1);
        for(auto &neighbor : adj[s1])
        {
            if(vis.find(neighbor.first) == vis.end())
            {

                res *= neighbor.second;
                if(dfs(adj, neighbor.first, s2, vis, res))
                {
                    return true;
                }

                res /= neighbor.second; // since we didn't find the answer in that search so we need to undo the multiplication
            }
        }
        return false;
    }
};


int main()
{
    return 0;
}