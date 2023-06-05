#include <iostream>
#include <vector>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    // constructor
    DisjointSet(int n)
    {
        // initially rank is zero for all
        rank.resize(n + 1, 0);
        // size for single node is one
        size.resize(n + 1, 1);

        // each node is parent of itself
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        // belong to the same component
        if (ulp_v == ulp_u)
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

    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        // belong to the same component
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

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);

    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);

    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not Same\n";

    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);

    if (ds.findPar(3) == ds.findPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not Same\n";

    return 0;
}