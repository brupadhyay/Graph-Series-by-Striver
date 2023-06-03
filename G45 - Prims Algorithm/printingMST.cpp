//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // E space
        vector<pair<int, int>> minimumEdges;

        // E
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        int vis[V] = {0};
        int sum = 0;

        pq.push({0, {0, -1}}); // {distance, node, parent};
        // E log E + E log E
        // E log E
        while (!pq.empty())
        {

            // log E
            auto it = pq.top();
            pq.pop();

            int dist = it.first;
            int node = it.second.first;
            int parent = it.second.second;

            if (vis[node])
                continue;

            // if not visited
            sum += dist;
            vis[node] = 1;

            if (parent != -1)
                minimumEdges.push_back({node, parent});
            // E log E
            for (auto it : adj[node])
            {
                int edW = it[1];
                int adjNode = it[0];
                if (!vis[adjNode])
                {
                    pq.push({edW, {adjNode, node}});
                }
            }
        }
        // printing MST
        for (auto it : minimumEdges)
        {
            cout << it.first << " -> " << it.second << endl;
        }
        return sum;
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
