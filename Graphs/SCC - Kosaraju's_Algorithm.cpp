/*
Explanation: The idea behind SCC is that if we start from any node in a component, we must be able to reach
all other nodes in that component. Note that by components here, we mean that we group certain nodes in 
the graph that meet the condition for every node in that component. The marked components in the following
graph are from an SCC.
Intuition: The idea behind KosaRaju’s algorithm is to do a DFS in a controlled fashion such that we won’t
be able to go from one SCC to other. One DFS call would visit all the nodes in an SCC only.
Approach :

Sort all the nodes according to their topo sort(loosely based topo sort as we may have cycles here)
Transpose the graph i.e reverse all the edges of the graph
Use the topo sort or the increasing order of finishing time to find the strongly connected components using DFS.
*/
#include <bits/stdc++.h>
using namespace std;

// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly
// connected components in the graph.
// Time Complexity: O(V+E).
// Auxiliary Space: O(V).
class Solution
{
    private:
    // this function is for dfs calls in step 3
    void dfs3(int node, vector<int> &vis, vector<int> adj[])
	{
	    vis[node] = 1;
	    for (auto it : adj[node])
	    {
	        if (!vis[it])
	        {
	            dfs3(it, vis, adj);
	        }
	    }
	}
	public:
	// for step 1
	void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
	{
	    vis[node] = 1;
	    for (auto it : adj[node])
	    {
	        if (!vis[it])
	        {
	            dfs(it, vis, adj, st);
	        }
	    }
	    // the node that triggered the dfs at first will be the last one to finish due to recursion
	    st.push(node);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // step 1 : sort all the nodes in order of finishing of dfs
        vector<int> vis(V, 0);
        // this stack will store the nodes in order of their completion (descending order)
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }
        
        // step 2 : reverse/transpose the graph
        // will store the edges in reverse order
        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            // mark the node as unvisited for step 3
            vis[i] = 0;
            for (auto it : adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        
        // step 3 : perform dfs on the reversed graph
        // scc will count the strongly connected components
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                // this if statement will only be visited if node is not, as recursion will mark all reachable
                // nodes as visited
                scc++;
                dfs3(node, vis, adjT);
            }
           
        }
        return scc;
    }
};