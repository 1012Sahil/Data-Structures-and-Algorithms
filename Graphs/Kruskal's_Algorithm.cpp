// First revise the Disjoint Set file for better understanding!
// Refer to Disjoint_Set.cpp

// In Kruskal's algorithm, we find a MST of a given graph. We have already studied one algorithm that does that
// : Prim's algorithm.

/*
Approach :
Sort all the edges according to their weight
Greedily pick minimum edge and make sure the two nodes belong to different components (using disjoint set
data structure findParent operation). Remember, if they belong to same component it would indicate we would
be having cycles which is not possible in a MST.
Also, once we a node to be a part of the MST, we must join the two components using the union
operation of DSU.
*/

/*
Time Complexity: O(ElogE)+O(E*4*alpha), ElogE for sorting and E*4*alpha for findParent operation ‘E’ times
Space Complexity: O(N). Parent array+Rank Array
*/

// Using a Disjoint Set for Kruskal's algorithm
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // For Kruskal's algorithm, we need the edges, and then sort them
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                // We should add the edge from u->v and v->u but it is going to be ignored anyway
                edges.push_back({wt, {node, adjNode}});
            }
        }

        DisjointSet ds(V);
        // sorting the edges by weight
        sort(edges.begin(), edges.end());

        int mstWt = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            // if the nodes are not part of same components, then join them by union and update mstWt
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};