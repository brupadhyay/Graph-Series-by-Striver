
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
  bool dfs(int src, int parent, vector<int> adj[], int vis[]){
      vis[src] = 1;
      
        for(auto adjNode: adj[src]){
            if(vis[adjNode] == 0){
                
                if(dfs(adjNode, src, adj, vis) == true){
                    return true;
                }
            } else {
                if( adjNode != parent){
                    return true;
                }
            }
        }
      return false;
  }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V+1] = {0};
        
        for(int i = 1; i <= V; i++){
            if( !vis[i] ){
                if( dfs(i, -1, adj, vis) == true ) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V+1];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}