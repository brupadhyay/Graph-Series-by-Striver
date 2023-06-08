/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis,
             int tin[], int low[], vector<int> &mark)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, adj, vis, tin, low, mark);
                // greedily take the lowest
                low[node] = min(low[node], low[it]);

                // if the adj. lowest possible is >= than node's insertion time
                // then definitely disconnecting node will lead to breaking
                if (low[it] >= tin[node] && parent != -1)
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                // visited node case:
                // or here we update lowest by comparing with insertion time
                // because I can't take above lowest insertion time
                low[node] = min(low[node], tin[it]);
            }
        }
        // to check if first node can break components
        if (child > 1 && parent == -1)
        {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        // O(3V)
        vector<int> vis(n, 0);

        int tin[n];
        int low[n];

        vector<int> mark(n, 0);

        // O(V + 2E)
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }

        vector<int> ans;
        // O(V)
        for (int i = 0; i < n; i++)
        {
            if (mark[i] == 1)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}