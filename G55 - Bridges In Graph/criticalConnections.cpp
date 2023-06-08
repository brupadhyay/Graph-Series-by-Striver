#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int timer = 0;
    vector<vector<int>> critical;
    void dfs(int node, int parent, vector<int> adjList[], vector<int> &vis, vector<int> &timeOfInsertion, vector<int> &lowestTime)
    {
        vis[node] = 1;
        timeOfInsertion[node] = lowestTime[node] = timer++;

        for (auto adjNode : adjList[node])
        {
            if (adjNode == parent)
                continue;
            if (!vis[adjNode])
            {
                dfs(adjNode, node, adjList, vis, timeOfInsertion, lowestTime);
                lowestTime[node] = min(lowestTime[node], lowestTime[adjNode]);
                if (timeOfInsertion[node] < lowestTime[adjNode])
                {
                    critical.push_back({node, adjNode});
                }
            }
            else
            {
                lowestTime[node] = min(lowestTime[node], lowestTime[adjNode]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // O(V + 2E)
        vector<int> adjList[n];

        for (auto edge : connections)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // O(3V)
        vector<int> vis(n, 0);
        vector<int> timeOfInsertion(n, 0);
        vector<int> lowestTime(n, 0);

        // O(V + 2E) - undirected graph dfs
        dfs(0, -1, adjList, vis, timeOfInsertion, lowestTime);
        return critical;
    }
};

int main()
{
    int n;
    cin >> n;

    // [[0,1],[1,2],[2,0],[1,3]]
    vector<vector<int>> connections;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        connections.push_back({u, v});
    }
    Solution obj;
    vector<vector<int>> ans = obj.criticalConnections(n, connections);
    for (auto edge : ans)
    {
        cout << edge[0] << "->" << edge[1] << "\n";
    }
}