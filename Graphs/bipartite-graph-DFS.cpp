#include <bits/stdc++.h>
using namespace std;

// If we are able to colour a graph with two colours such that no adjacent nodes have the same colour,
// it is called a bipartite graph.

/* Intuition:.
A bipartite graph is a graph which can be coloured using 2 colours such that no adjacent
nodes have the same colour. Any linear graph with no cycle is always a bipartite graph.
With a cycle, any graph with an even cycle length can also be a bipartite graph.
So, any graph with an odd cycle length can never be a bipartite graph.

The intuition is the brute force of filling colours using any traversal technique,
just make sure no two adjacent nodes have the same colour. If at any moment of traversal,
we find the adjacent nodes to have the same colour, it means that there is an odd cycle,
or it cannot be a bipartite graph. */

// DFS solution
/* Time Complexity: O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.
Space Complexity: O(3V) ~ O(V), Space for DFS stack space, colour array and an adjacency list. */
class Solution
{
private:
    bool dfs(int node, int col, int color[], vector<int> adj[])
    {
        color[node] = col;

        // traverse adjacent nodes
        for (auto it : adj[node])
        {
            // if uncoloured
            if (color[it] == -1)
            {
                if (dfs(it, !col, color, adj) == false)
                    return false;
            }
            // if previously coloured and have the same colour
            else if (color[it] == col)
            {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;

        // for connected components
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, 0, color, adj) == false)
                    return false;
            }
        }
        return true;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}