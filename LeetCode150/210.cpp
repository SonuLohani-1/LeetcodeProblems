#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 210 on Leetcode - Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/

// The solution is very similar to the solution of course schedule problem
// here I have used the same approach but also stored the topological sort in the ans vector
// The time complexity is O(V+E) and space complexity is O(V+E)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> course_order;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            course_order.push_back(node);
            for(auto i : graph[node])
            {
                indegree[i]--;
                if(indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        if(course_order.size() != numCourses) return {};
        return course_order;
    }
};

int main()
{
    return 0;
}