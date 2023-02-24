//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int r, int c, vector<vector<int>> &grid, 
    vector<vector<int>> &vis, int delrow[], int delcol[]){
        vis[r][c] = 1;
        int n = grid.size(), m = grid[0].size();
        
        for(int i = 0; i < 4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis, delrow, delcol);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int delrow[] = {-1,0,1,0}, delcol[] = {0, 1, 0, -1};
        
        //traversing the boundaries
        //first and last row and infecting all those who are not part of my answer
        for(int i = 0; i < m; i++){
            //first row
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(0 , i, grid, vis, delrow, delcol);
            }
            //last row
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                dfs(n-1 , i, grid, vis, delrow, delcol);
            }
            
        }
        //first and last column
        for(int i = 0; i < n; i++){
            //first row
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, grid, vis, delrow, delcol);
            }
            //last row
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i, m-1 , grid, vis, delrow, delcol);
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