#include<bits/stdc++.h>
using namespace std;
    
int main(){

    int n, m;
    cin>>n>>m;
    // Graph here

    // Initialize the adjacency matrix with 0 (no edges)
    int adj[n+1][n+1] = {0};  // 1-based indexing
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        // Since this is an undirected graph, set both adj[u][v] and adj[v][u] to 1
        adj[u][v] = 1;
        adj[v][u] = 1;
    }   


    // Print the adjacency matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}