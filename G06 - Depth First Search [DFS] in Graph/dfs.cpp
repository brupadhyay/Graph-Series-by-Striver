#include <iostream>
#include <vector>
using namespace std;


class Solution{
    public:

    void solve(int stNode, vector<int> adj[], vector<int> &ls, int vis[]){
        vis[stNode] = 1;
        ls.push_back(stNode);

        for(auto it: adj[stNode]){
            if(!vis[it]){
                solve(it, adj, ls, vis);
            }
        }
    }

    vector<int> dfsOfGraph(vector<int> *adj, int startNode, int n){
        //visited array
        int vis[n+1] = {0};

        vector<int> ls;
        solve(startNode, adj, ls, vis);
        return ls;
    }
};

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // u --> v
        adj[v].push_back(u); // v --> u
    }


    Solution obj;
    vector<int> dfs = obj.dfsOfGraph(adj, 1, n);

    for(int i: dfs){
        cout << i << " ";
    }



    return 0;
}