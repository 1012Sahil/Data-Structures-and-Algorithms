#include <bits/stdc++.h>
using namespace std;

// Space complexity : O(N) + O(N) = O(N)
/*                      |      |
                Recursion    Traversing the
                call stack   adjacency list
*/

// Time complexity : O(V) + O(2E)
void dfs(int node, vector<int> adjLs[], int vis[])
{
    vis[node] = 1;
    for (auto it : adjLs[node])
    {
        if (!vis[it])
        {
            // dfs call for neighbours
            dfs(it, adjLs, vis);
        }
    }
}

int numberOfProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjLs[V];

    // to change adjacency matrix to list
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }

        // Graph node starts from zero!
        int vis[V] = {0};
        // cnt is a counter that keeps track of number of provinces, for each unique dfs call, we update the cnt variable
        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            // While we traverse the entire graph, we only use dfs call one time by keeping track of the visited array
            if (!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
}