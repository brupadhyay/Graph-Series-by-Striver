
#include <bits/stdc++.h>
using namespace std;

// Why queue and not priority queue
//O(4*n*m)

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[source.first][source.second] = 0;
        
        queue<pair<int,pair<int,int> > > q;
        q.push({0, source});
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            
            for(int i = 0;i<4;i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && grid[nrow][ncol] != 0 ){
                    if(dis + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dis + 1;
                        if(destination.first == nrow && destination.second == ncol){
                            return dis + 1;
                        }
                        q.push(make_pair(dis + 1,make_pair(nrow, ncol)));
                    }
                }
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}
