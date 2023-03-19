

#include <bits/stdc++.h>
using namespace std;

//TC - O(N + 2M) SC - O(N + 2M)

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(N,INT_MAX);
        
        dist[src] = 0;
        
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(dis + 1 < dist[it]){
                    dist[it] = dis + 1;
                    q.push({it, dist[it]});
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(dist[i] == INT_MAX) dist[i] = -1; 
        }
        
        return dist;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}
