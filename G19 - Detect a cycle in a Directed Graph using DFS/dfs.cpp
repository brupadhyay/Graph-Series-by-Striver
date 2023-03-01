
#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(2V) + O(V) ~ O(2V): O(2V) for two visited arrays and O(V) for recursive stack space.*/

class Solution {
  private:
  bool dfs(int src, vector<int> adj[], int vis[], int samePath[]){
      vis[src] = 1;
      samePath[src] = 1;
      
      //traverse for adjacent nodes
      for(auto it: adj[src]){
          //if node is not visited then
          if(!vis[it]){
              if(dfs(it, adj, vis, samePath) == true) return true;
          } else {
              //if node has been previously visited
              //it has to be in the same path
              if(samePath[it]){
                  return true;
              }
          }
      }
      samePath[src] = 0; //backtrack the samePath because you came back from the call
      return false;
  }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        int samePath[V] = {0};
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if( dfs(i , adj, vis, samePath) == true){
                    return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends