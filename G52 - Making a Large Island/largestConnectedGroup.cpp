/*You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.

You can change at most one cell in grid from 0 to 1.

You need to find the largest group of connected  1's.

Two cells are said to be connected if both are adjacent to each other and both have same value.*/
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    // n*n x 2
    vector<int> size, parent;
    DisjointSet(int n)
    {
        size.resize(n, 1);
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

    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
        else
        {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

class Solution
{
    bool isValid(int r, int c, int n)
    {
        return r >= 0 && c >= 0 && c < n && r < n;
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();

        DisjointSet ds(n * n);

        vector<vector<int>> vis(n, vector<int>(n, 0));

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // n x n x (4 x alpha)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    int node = i * n + j;
                    vis[i][j] = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = delrow[k] + i;
                        int ncol = delcol[k] + j;
                        if (isValid(nrow, ncol, n) &&
                            !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                        {
                            int adjNode = nrow * n + ncol;

                            ds.unionBySize(adjNode, node);
                        }
                    }
                }
            }
        }

        int maxIsland = 0;

        // n x n x 4 x alpha
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int curr = 1;
                    set<int> components;
                    for (int k = 0; k < 4; k++)
                    {
                        int nrow = delrow[k] + i;
                        int ncol = delcol[k] + j;

                        if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1)
                        {
                            int adjNode = nrow * n + ncol;
                            // log 4 ~ constant
                            components.insert(ds.findPar(adjNode));
                        }
                    }
                    for (auto it : components)
                    {
                        curr += ds.size[it];
                    }
                    maxIsland = max(maxIsland, curr);
                }
            }
        }

        for (auto it : ds.size)
        {
            maxIsland = max(maxIsland, it);
        }

        return maxIsland;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}
