
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image,
    int iniColor, int newColor, int delrow[], int delcol[]){
        
        ans[row][col] = newColor;
        int n = image.size(), m = image[0].size();
        
        for(int i = 0; i < 4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, image, iniColor, newColor, delrow, delcol);
            }
        }
        
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = { 0, +1, 0, -1};
        dfs(sr, sc, ans, image, iniColor, newColor, delrow, delcol);
        return ans;
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