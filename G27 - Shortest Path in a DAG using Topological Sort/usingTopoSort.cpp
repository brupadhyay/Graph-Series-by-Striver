
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
  void dfs(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &st){
      vis[node] = 1;
      
      for(auto it: adj[node]){
          if(!vis[it.first]) dfs(it.first, adj, vis, st);
      }
      st.push(node);
  }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[N];
        
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        
        stack<int> st;
        int vis[N] = {0};

        //O(N + E)
        for(int i = 0; i < N; i++){
            if(!vis[i])
                dfs(i, adj, vis, st);
        }
        
        vector<int> dist(N, 1e9);
        
        dist[0] = 0;
        
        //O(N + M)
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            int dis = dist[node];
            
            for(auto it: adj[node]){
                //relaxing the edges
                dist[it.first] = min(dist[it.first], dis + it.second);
            }
        }
        
        for (int i = 0; i < N; i++) {
            //if unable to reach the node, we mark the vertex as -1
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
