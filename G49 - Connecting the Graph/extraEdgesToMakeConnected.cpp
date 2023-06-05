#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findPar(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge)
    {
        int numberOfConnectedComponents = 0;
        int extraEdges = 0;
        DisjointSet ds(n);

        // E x 4 x alpha
        for (auto it : edge)
        {
            if (ds.findPar(it[0]) == ds.findPar(it[1]))
            {
                extraEdges++;
            }
            else
                ds.unionByRank(it[0], it[1]);
        }
        // N * 4 x alpha
        for (int i = 0; i < n; i++)
        {
            if (ds.findPar(i) == i)
                numberOfConnectedComponents++;
        }
        bool isPossible = extraEdges >= numberOfConnectedComponents - 1;
        return isPossible ? numberOfConnectedComponents - 1 : -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 2; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}