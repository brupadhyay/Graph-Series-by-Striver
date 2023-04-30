#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX)); // O(V^2)
        for(auto it: edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j) dist[i][j] = 0;
            }
        }
        
        // O(V^3)
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int minCities = n;
        int city = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= minCities){
                minCities = cnt;
                city = i;
            }
        }
        return city;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}
