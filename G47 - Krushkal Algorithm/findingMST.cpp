#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> size, parent;

public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findUPar(parent[u]); // path compression
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sumMST = 0;

        vector<pair<int, pair<int, int>>> edges;

        // V + E
        for (int u = 0; u < V; u++)
        {
            for (auto it : adj[u])
            {
                int v = it[0];
                int w = it[1];
                edges.push_back({w, {u, v}});
            }
        }
        // M log M , where M - edges
        sort(begin(edges), end(edges));
        DisjointSet ds(V);

        // M x 4 x alpha x 2
        for (auto it : edges)
        {
            int edgeW = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) == ds.findUPar(v))
                continue;

            sumMST += edgeW;
            ds.unionBySize(u, v);
        }

        return sumMST;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
