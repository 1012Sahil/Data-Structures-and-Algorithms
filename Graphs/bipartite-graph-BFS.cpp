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

// BFS solution
/* Time Complexity: O(V + 2E), Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.
Space Complexity: O(3V) ~ O(V), Space for queue data structure, colour array and an adjacency list.*/
class Solution
{
    // colors a component
private:
    bool check(int start, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : adj[node])
            {
                // if the adjacent node is yet not colored
                // you will give the opposite color of the node
                if (color[it] == -1)
                {

                    color[it] = !color[node];
                    q.push(it);
                }
                // is the adjacent guy having the same color
                // someone did color it on some other path
                else if (color[it] == color[node])
                {
                    return false;
                }
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

        for (int i = 0; i < V; i++)
        {
            // if not coloured
            if (color[i] == -1)
            {
                if (check(i, V, adj, color) == false)
                {
                    return false;
                }
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

