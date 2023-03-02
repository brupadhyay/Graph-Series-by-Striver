//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  private:
   bool isCycle(vector<int>adj[],  int vis[], int node, int pathVis[]){

        vis[node] = 1;

        pathVis[node] = 1;

        

        for(auto it: adj[node]){

            if(vis[it] == 0){

              if( isCycle(adj, vis, it, pathVis) == true) return true;

            }

            else if(pathVis[it] == 1) return true;

        }

        pathVis[node] = 0;

        return false;

    }
  void dfs(int node, int vis[], vector<int> adj[], stack<int> &st){
      vis[node] = 1;
      
      for(auto it: adj[node]){
          if(!vis[it]){
              dfs(it, vis, adj, st);
          }
      }
      
      st.push(node);
  }
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        int vis[n] = {0};
        int pathVis[n] = {0};
        
        vector<int> ans;
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                if(isCycle(adj, vis, i, pathVis) == true) return {};
            }
        }
        
        for(int i = 0; i < n ; i++ ) vis[i] = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends