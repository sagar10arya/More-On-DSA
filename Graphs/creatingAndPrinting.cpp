#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.

In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.
*/
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int> ans[n];
    // ans array will store adjacent nodes
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v= edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);  // undirected graph
    }

    vector<vector<int>> adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);
        
        // entering neighbours
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}