//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int delrow[] = {-1,0,1,0}, delcol[] = {0, 1, 0, -1};
        
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //first, last row/col
                if( i == 0 || j == 0 || j == m - 1 || i == n - 1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i] , ncol = c + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !vis[nrow][ncol] && grid[nrow][ncol] == 1){

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                    
                }
            }
        }
        
        
        int cnt = 0;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends