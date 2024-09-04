#include<bits/stdc++.h>
using namespace std;

/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.
*/

/* Using DFS */
class Solution {
    
    private:
    
    bool dfs(int node, int parent, int vis[], vector<int> adj[])
    {
        vis[node] = 1;
        
        for(auto adjacentNode : adj[node]){
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, vis, adj) == true) return true;
            }
            else if(parent != adjacentNode) return true;
        }
        
        return false;
    }

  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};