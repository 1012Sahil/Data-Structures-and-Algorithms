#include <bits/stdc++.h>
using namespace std;

// In this code, node starts from 0, not 1, so we created an array vis of V size not V+1
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    // traverse all its neighbours using a for each loop
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}
// Given the adjacency list of the graph, print the DFS traversal of the graph.

// Function to return a list containing the DFS traversal of the graph
// V is the number of nodes and adj[] is the adjacency list
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Assuming starting node here to be 0, can be taken from user if required
    int vis[V] = {0};
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}