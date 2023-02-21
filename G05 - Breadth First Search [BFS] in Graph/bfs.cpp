#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define pb push_back

//Time Complexity - O(n) + O(2E), Space Complexity - O(3n) ~ O(n)

vector<int> bfsTraversal(int n, vector<int> *adj){
    vector<int> bfs;
    int visited[n] = {0};
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.pb(node);

        for(int i = 0; i < adj[node].size(); i++){
            int neighbor = adj[node][i];
            if(!visited[neighbor]){
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
    return bfs;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); //u ---> v
        adj[v].push_back(u); //v ---> u
    }

    vector<int> bfs = bfsTraversal(n, adj);

    for(int i = 0; i < bfs.size(); i++){
        cout << bfs[i] << " "; 
    }
    cout << endl;

    return 0;
}