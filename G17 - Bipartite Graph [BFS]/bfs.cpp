
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.

// Space Complexity: O(3V) ~ O(V), Space for DFS stack space, colour array and an adjacency list.
class Solution {
    bool check(int start, int V, vector<int> adj[], int colour[]){
        queue<int> q;
	    q.push(start);
	    colour[start] = 0;
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        
	        for(auto it: adj[node]){
	            if(colour[it] == -1){
	                colour[it] =  colour[node];
	                q.push(it);
	            } else{
	                if(colour[it] == colour[node])
	                    return false;
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int colour[V];
	    
	   for(int i = 0; i < V; i++)   colour[i] = -1;
	   
	   for(int i = 0; i < V; i++){
	       if(colour[i] == -1){
	           if(check(i, V, adj,  colour) == false){
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