//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(int src ,int V, vector<int> adj[], int vis[], int col){
        vis[src] = !col;
        
        for(auto it: adj[src]){
            if(vis[it] == -1){
                if(dfs(it, V, adj, vis, vis[src]) == false) return false;
            } else {
                if(vis[it] == vis[src]){
                    return false;
                }
            }
        }
        return true;
        
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	   int vis[V];
	    
	   for(int i = 0; i < V; i++) vis[i] = -1;
	   
	   for(int i = 0; i < V; i++){
	       if(vis[i] == -1){
	           if(dfs(i, V, adj, vis, 1) == false){
	               return false;
	           }
	       }
	   }
	   return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends