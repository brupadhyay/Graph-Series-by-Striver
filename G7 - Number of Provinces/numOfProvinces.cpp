#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define pb push_back

void dfs(int stNode, vector<int> adjLs[], int vis[]){
    vis[stNode] = 1;

    for(auto it: adjLs[stNode]){
        if(!vis[it]){
            dfs(it, adjLs, vis);
        }
    }
}

void bfs(int node, vector<int> *adj, int vis[]){
    queue<int> q;
    q.push(node);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i < adj[node].size(); i++){
            int neighbor = adj[node][i];
            if(!vis[neighbor]){
                vis[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int adj[n][n];

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int edge;
            cin >> edge;
            adj[i][j] = edge;
        }
    }

    vector<int> adjLs[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //self nodes not considered
            if(adj[i][j] == 1 && i != j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }            
        }
    }

    int vis[n] = {0};
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjLs, vis);
            // bfs(i, adjLs, vis);
        }
    }
    
    cout << cnt << endl;


}