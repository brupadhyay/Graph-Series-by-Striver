#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][n+1];
    //adjacency matrix for Undirected Graph
    //TC - O(m) SC - O(n*n)
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; //in case of directed graph this won't appear
    }

    //if weighted graph is given
    /*for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w; //in case of directed graph this won't appear
    }*/
    cout << endl;
    return 0;
}