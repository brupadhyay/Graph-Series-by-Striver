//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            // u -- u
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        vector<int> pathsWithShortestDistance(n, 0);
        pathsWithShortestDistance[0] = 1;
        
        priority_queue<pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>> > pq;
        pq.push({0, 0});
        
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty()){
            int node = pq.top().second;
            long dis = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                long edW = it.second;
                
                long currDistance = dis + edW;
                
                
                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if(currDistance < dist[adjNode]){
                    dist[adjNode] = currDistance;
                    pq.push({currDistance, adjNode});
                    pathsWithShortestDistance[adjNode] = pathsWithShortestDistance[node];
                }
                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.                
                else if(currDistance == dist[adjNode]){
                    pathsWithShortestDistance[adjNode] += pathsWithShortestDistance[node] % mod;
                }
            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return pathsWithShortestDistance[n-1];
        
    }
};


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}