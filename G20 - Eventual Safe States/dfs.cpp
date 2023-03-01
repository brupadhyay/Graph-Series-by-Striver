// modifying the cycle detection in Directed Graph using DFS
/*A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.*/
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// User function Template for C++

class Solution {
  private:
  bool dfs(int src, int vis[], int pathVis[], int check[], vector<int> adj[]){
      vis[src] = 1;
      pathVis[src] = 1;
      
      for(auto it: adj[src]){
          if(!vis[it]){
              //not visited
              if(dfs(it, vis, pathVis, check, adj) == true){
                //if one of the adjacent returns true 
                //means one of the path of src is a 
                //part of a cycle hence src is not a safe node
                  check[src] = 0;
                  return true;
              }
          }
           else {
               //if previously visited and same path
               if(pathVis[it]){
                   check[src] = 0; //can't be a safe node
                   return true;
               }
           }
      }
      //if completed all the check 
      //and not found a cycle its safeNode
      check[src] = 1; 
      pathVis[src] = 0;
      return false;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0}, pathVis[V] = {0};
        int check[V] = {0};
        
        vector<int> safeNodes;
        
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, check, adj);
            }
        }
        for(int i =0; i < V; i++){
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};



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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}
