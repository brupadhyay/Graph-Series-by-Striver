//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool isValid(int r, int c, int n, int m){
        return (r >= 0 && c >= 0 && r < n && c < m);
    }
    
    void bfs(int row, int col, vector<vector<int>> &vis,vector<vector<int>>& grid
    , vector<pair<int,int>> &vec, int delrow[], int delcol[], int row0, int col0){
        vis[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        
        queue<pair<int,int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            vec.push_back({row - row0, col - col0});
            
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if( isValid(nrow, ncol, n, m) &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
            
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0)); // n x m
        
        set<vector<pair<int,int>>> st; //n x m
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    // n x m x 4
                    bfs(i , j, vis, grid, vec, delrow, delcol, i, j);
                    st.insert(vec);
                }
            }
        }
        //n x m + (n x m x 4)
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends