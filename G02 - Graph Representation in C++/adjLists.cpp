#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    //adjacency lists for undirected graph
    //Space Complexity - O(2E)
    //For Directed Graph SC - O(E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        //u ---> v & v ---> u
        adj[u].push_back(v);
        adj[v].push_back(u); //this will be removed for directed graph
    }

    for(int i = 1; i < n+1; i++){
        vector<int> list = adj[i];

        cout << i << " -> { ";
        for(int node: list){
            cout << node << " ";
        }
        cout << "} " << endl;
    }
    cout << endl;


    return 0;
}