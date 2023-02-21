
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        //n x m
        int vis[n][m];
        //n x m
        queue<pair<pair<int,int>,int>> q;
        int cntFresh = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else {
                    vis[i][j] = 0;
                }
                
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        
        int tm = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max(tm, t);
            
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            
            for(int i = 0; i < 4; i++){
                int nrow = delrow[i] + r;
                int ncol = delcol[i] + c;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t + 1});
                    cntFresh--;
                }
            }
        }
        
        return cntFresh != 0 ? -1 : tm;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends