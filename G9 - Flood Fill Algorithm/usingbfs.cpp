#include<bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(int row, int col, int newColor, vector<vector<int>> &flood,
    vector<vector<int>> image, int initialColor){
        
        queue<pair<int, int>> q;
        flood[row][col] = newColor;
        int n = image.size(), m = image[0].size();
        
        q.push({row, col});
        
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            
            vector<vector<int>> pathToFollow{
                {r - 1, c},
                {r + 1, c},
                {r, c + 1},
                {r, c - 1}
            };
            
            for(auto it: pathToFollow){
                int nrow = it[0];
                int ncol = it[1];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                image[nrow][ncol] == initialColor && flood[nrow][ncol] != newColor) {
                    q.push({nrow, ncol});
                    flood[nrow][ncol] = newColor;
                }
            }
            
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size(), m = image[0].size();
        
        vector<vector<int>> flood = image;
        
        int initialColor = image[sr][sc];
        bfs(sr, sc, newColor, flood, image, initialColor);
        return flood;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}