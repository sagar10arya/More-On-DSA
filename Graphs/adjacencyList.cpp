#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin>>n>>m;
    // Graph here
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print the adjacency list
    for(int i = 1; i <= n; i++) {  // Start from 1 to match 1-based indexing
        cout << i << ": ";  // Print the vertex number
        for(int j : adj[i]) {
            cout << j << " ";  // Print all vertices connected to vertex i
        }
        cout << endl;
    }

    return 0;
}