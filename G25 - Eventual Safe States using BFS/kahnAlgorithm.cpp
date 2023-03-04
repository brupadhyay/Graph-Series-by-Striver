

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indegree[V] = {0};
        
        for(int i = 0;i<V;i++){
            // i --> it
            // it --> i
            // 2 - {1, 3}
            // 1 -> {2}, 3 -> {2}
            // indegree[2] = 2
            for(auto it: adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            for(auto it: adjRev[node]){
                if (--indegree[it] == 0) q.push(it);
            }
        }
        // O(V+E) + O(nlogn) where n is size(ans)
        // O(3N), indegree, Queue, adj Reverse List
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends