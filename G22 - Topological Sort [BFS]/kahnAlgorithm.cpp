//Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// Famously known as KAHN's ALGORITHM


#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0};
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i = 0;i<V;i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
            //node is with 0 indegree so apparently
            //no node will be placed before it, just omit it from the indegree
	        ans.push_back(node);
	        
	        for(auto it: adj[node]){
                //if any adjacent nodes indegree is zero, push the node to the queue
	            if(--indegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
	}
};


/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
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
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}