#include <iostream>
#include <queue>
using namespace std;


void bfs(int row, int col,vector<vector<char>> grid, vector<vector<int>> &vis){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row, col});
    int n = grid.size(), m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int delrow = -1; delrow <= 1; delrow++){
            for(int delcol = -1; delcol <= 1; delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if( (nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) 
                && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n,vector<char>(m,'0'));
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            grid[i][j] = c;
        }
    }

    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));


    for(int row = 0 ; row < n; row++){
        for(int col = 0; col < m; col++){
            if(!vis[row][col] && grid[row][col] == '1'){
                bfs(row, col, grid, vis);
                cnt++;
            }
        }
    }

    cout << cnt;
    

}