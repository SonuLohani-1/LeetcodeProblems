#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 207 on Leetcode - Course Schedule
// https://leetcode.com/problems/course-schedule/

// The problem can be solved using the topological sort
// The idea is to use the graph data structure and then use the topological sort to find the order of the courses
// The time complexity is O(V+E) and space complexity is O(V+E)
// Step by step explanation:
// 1. Create a graph with the given prerequisites
// 2. Create a vector to store the indegree of each node
// 3. Push all the nodes with indegree 0 in the queue
// 4. While the queue is not empty, pop the front element and push it in the ans vector
// 5. For each of the adjacent nodes of the popped element, decrease the indegree by 1
// 6. If the indegree of any node becomes 0, push it in the queue

class Solution {
    public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto i: prerequisites){
            graph[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // vector<int> ans; // Here we don't require the topological sort so we don't need to store the ans
        int ans = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans++;
            for(auto i: graph[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        return ans==numCourses;
    }
};
int main()
{
    return 0;
}