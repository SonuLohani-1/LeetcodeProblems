#include<bits/stdc++.h>
using namespace std;

// This is the solution of the problem 117 on leetcode - Populating Next Right Pointers in Each Node II
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

// The idea is to use level order traversal and use a queue to store the nodes of each level

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == NULL){
            return NULL;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            
            for(int i=0;i<n;i++){
                
                Node* curr = q.front();
                q.pop();
                
                if(i == n-1){
                    curr->next = NULL;
                }
                else{
                    curr->next = q.front();
                }
                
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
        }
        
        return root;
    }
};
int main()
{
    return 0;
}