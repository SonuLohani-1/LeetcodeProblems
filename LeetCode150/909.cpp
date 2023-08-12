#include<bits/stdc++.h>
using namespace std;
// This is the solution of the problem 909 on Leetcode - Snake and Ladders
// https://leetcode.com/problems/snakes-and-ladders/

// The idea is to use BFS to find the shortest path to the end of the board

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> v(n*n+1, -1);
        int count = 1;
        bool left = true;
        for(int i = n-1; i >= 0; i--)
        {
            if(left)
            {
                for(int j = 0; j < n; j++)
                {
                    v[count++] = board[i][j];
                }
            }
            else
            {
                for(int j = n-1; j >= 0; j--)
                {
                    v[count++] = board[i][j];
                }
            }
            left = !left;
        }
        
        queue<int> q;
        q.push(1);
        vector<int> dist(n*n+1, INT_MAX);
        dist[1] = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i = 1; i <= 6; i++){
                int next = curr + i;
                if(next > n*n) break;
                if(v[next] != -1) next = v[next];
                if(dist[next] > dist[curr] + 1){
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
        return dist[n*n] == INT_MAX ? -1 : dist[n*n];
    }
};
int main()
{
    return 0;
}