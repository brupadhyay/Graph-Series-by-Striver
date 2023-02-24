//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(int row, int col, vector<vector<char>> mat, vector<vector<int>> &vis,
    int delrow[], int delcol[]){
        int n = mat.size(), m = mat[0].size();
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < n & ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                dfs(nrow, ncol, mat, vis, delrow, delcol);
            }
            
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        for(int j = 0; j < m; j++){
            
            //check for first row
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0, j, mat, vis, delrow, delcol);
            }
            
            
            //check for last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1, j, mat, vis, delrow, delcol);
            }
        }
        
        for(int i = 0; i < n; i++){
            //check for first column
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0 , mat, vis, delrow, delcol);
            }
            
            //check for last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, mat, vis, delrow, delcol);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin >> mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends