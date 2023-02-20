#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    //adjacency lists for undirected graph
    //Space Complexity - O(2E)
    //For Directed Graph SC - O(E)
    vector< pair<int,int> > adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        //u ---> v & v ---> u
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w)); //this will be removed for directed graph
    }

    for(int i = 1; i < n+1; i++){
        auto list = adj[i];

        cout << i << " -> { ";
        for(pair<int,int> node: list){
            cout << "(" << node.first << ", " << node.second << ")";
        }
        cout << "} " << endl;
    }
    cout << endl;


    return 0;
}