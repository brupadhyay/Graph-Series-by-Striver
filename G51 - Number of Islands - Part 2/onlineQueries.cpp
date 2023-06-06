/*You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.*/
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
    bool isValid(int r, int c, int n, int m)
    {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        int totalComponents = n * m;

        // n
        DisjointSet ds(totalComponents);
        vector<int> ans;

        int vis[n][m];
        // n x m
        memset(vis, 0, sizeof vis);

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int cnt = 0;

        // Q x 4 x alpha
        for (auto it : operators)
        {
            int row = it[0];
            int col = it[1];

            if (vis[row][col])
            {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (isValid(nrow, ncol, n, m) && vis[nrow][ncol])
                {
                    if (ds.findPar(nrow * m + ncol) != ds.findPar(row * m + col))
                    {
                        cnt--;
                        ds.unionBySize(nrow * m + ncol, row * m + col);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> a;

        for (int i = 0; i < k; i++)
        {
            vector<int> temp;
            for (int j = 0; j < 2; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.numOfIslands(n, m, a);

        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
}
