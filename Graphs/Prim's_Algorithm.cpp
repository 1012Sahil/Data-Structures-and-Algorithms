// A minimum spanning tree of a graph of n nodes is a graph(tree) of n nodes and n - 1 edges, such that each
// node is reachable by any other node!

// It starts with an empty spanning tree. The idea is to maintain two sets of vertices. The first set contains
// the vertices already included in the MST, the other set contains the vertices not yet included.
// At every step, it considers all the edges that connect the two sets and picks the minimum weight
// edge from these edges. After picking the edge, it moves the other endpoint of the edge to the
// set containing MST.

// Follow the given steps to find MST using Prim’s Algorithm:
// Create a set mstSet that keeps track of vertices already included in MST.
// Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE.
// Assign the key value as 0 for the first vertex so that it is picked first.
// While mstSet doesn’t include all vertices -
// Pick a vertex u which is not there in mstSet and has a minimum key value.
// Include u in the mstSet.
// Update the key value of all adjacent vertices of u. To update the key values, iterate through all
// adjacent vertices. For every adjacent vertex v, if the weight of edge u-v is less than the previous key
// value of v, update the key value as the weight of u-v

// Time Complexity : E log(E)

// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum
// of weights of the edges of the Minimum Spanning Tree.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> vis(V, 0);
        pq.push({0, 0}); // (weight, node) ---> no parent needed for just getting sum
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int weight = it.first;

            if (vis[node] == 1)
                continue;
            // add it to the MST
            vis[node] = 1;
            sum += weight;

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};