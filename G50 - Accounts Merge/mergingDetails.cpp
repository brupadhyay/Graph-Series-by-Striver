
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> mpp;
        int n = accounts.size();
        DisjointSet ds(n);

        // N + E x 4 alpha
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mpp.count(accounts[i][j]) == 0)
                {
                    mpp[accounts[i][j]] = i;
                }
                else
                {
                    ds.unionBySize(mpp[accounts[i][j]], i);
                }
            }
        }
        vector<string> merged[n];
        // E x 4 alpha
        for (auto it : mpp)
        {
            int node = it.second;
            string email = it.first;
            merged[ds.findPar(node)].push_back(email);
        }
        vector<vector<string>> ans;

        // N x (E log E + E)
        for (int i = 0; i < n; i++)
        {
            vector<string> v = merged[i];
            if (v.size() == 0)
                continue;

            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[i][0]);
            sort(v.begin(), v.end());
            for (auto s : v)
            {
                mergedAccount.push_back(s);
            }
            ans.push_back(mergedAccount);
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
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++)
        {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i)
        {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]"
             << endl;
    }
}