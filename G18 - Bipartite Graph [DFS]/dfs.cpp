
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.

// Space Complexity: O(3V) ~ O(V), Space for DFS stack space, colour array and an adjacency list.
class Solution {
    bool dfs(int src ,int V, vector<int> adj[], int colour[], int color){
        colour[src] = color;
        
        for(auto it: adj[src]){
            //if it is not colored go and color
            if(colour[it] == -1){
                if(dfs(it, V, adj, colour, !color) == false) return false;
            } else {
                //if it is coloured then check if the current node's color is equal to the adjacent one
                //if equal thereby u say it's not a bipartite graph
                if(colour[it] == color){
                    return false;
                }
            }
        }
        return true; //if after all degrees no one gave a problem return true
        
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	   int colour[V];
	    
	   for(int i = 0; i < V; i++) colour[i] = -1;
	   
	   for(int i = 0; i < V; i++){
        //check for every connected components
	       if(colour[i] == -1){
	           if(dfs(i, V, adj, colour, 0) == false){
	               return false;
	           }
	       }
	   }
	   return true;
	    
	}

};

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