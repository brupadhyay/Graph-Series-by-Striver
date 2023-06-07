/*Strongly Connected Components – Kosaraju’s Algorithm : G - 54 Problem Statement : Given a Directed Graph with V vertices(Numbered from 0 to V - 1) and E edges, Find the number of strongly connected components in the graph.*/

/*Two Types Of Question - 1. No of SCCs
                        2. Print the SCCs */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    stack<int> st;

    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
                dfs(adjNode, vis, adj);
        }
        st.push(node);
    }

    void dfsRev(int node, vector<int> &vis, vector<int> adjTList[],
                vector<int> &sccNodes)
    {
        vis[node] = 1;
        sccNodes.push_back(node);

        for (auto adjNode : adjTList[node])
        {
            if (!vis[adjNode])
                dfsRev(adjNode, vis, adjTList, sccNodes);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {

        vector<int> vis(V, 0);
        // V + E
        // sorting nodes according to the finish time
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj);
            }
        }

        // reversing the edges
        vector<int> adjTList[V];

        // V + E
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto it : adj[i])
            {
                // 1 --> 0
                // 0 --> 1
                adjTList[it].push_back(i);
            }
        }

        int scc = 0;

        vector<vector<int>> storeTheSCC;
        // V + E
        // counting the strongly connected components
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            vector<int> sccNodes;

            if (!vis[node])
            {
                scc++;
                dfsRev(node, vis, adjTList, sccNodes);
            }
            storeTheSCC.push_back(sccNodes);
        }

        for (auto it : storeTheSCC)
        {
            for (auto x : it)
            {
                cout << x;
            }
            cout << endl;
        }
        return scc;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
