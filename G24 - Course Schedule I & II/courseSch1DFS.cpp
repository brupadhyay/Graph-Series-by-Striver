//if cycle dependency is there I cannot finish all the possible tasks
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int node, int vis[], int pathVis[], vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                if( dfs(it, vis, pathVis, adj) == true) return true;
            } else {
                if(pathVis[it]){
                    return true;
                }
            }
        }
        pathVis[node] = 0;
        return false;
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    //cycle detection in a directed graph
	    int vis[N] = {0};
	    int pathVis[N] = {0};
	    vector<int> adj[N];
	    
	    for(auto it: prerequisites){
	        adj[it.second].push_back(it.first);
	    }
	    
	    for(int i = 0; i < N; i++){
	        if(!vis[i]){
	            if( dfs(i, vis, pathVis, adj) == true) return false;
	        }
	    }
	    return true;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}