// Dijkstra's Algorithm will not work for negative weighted graphs because the traversal will fall
// into an infinite loop, as the distance keeps on decreasing, it will go back and forth b/w
// the two nodes and never stop!

// The Bellman Ford Algorithm gives us a solution to this quandry! 
// This algorithm helps us to detect negative cycles.
// Negative Cycle: A cycle is called a negative cycle if the sum of all its weights becomes negative.
// Applicable only in directed graphs, so convert UDG to DG to use the algorithm
// Edges can be any particular order

// First relax the graph for all the edges! After N-1 iterations, we should have minimized the distance
// to every node. We need N-1 iterations for the simple reason that atmost N-1 checks of conditions will be
// done. Watch a video if difficulty in understanding

// Let's consider the graph u----wt---->v with dist[u], dist[v], and wt. Here, wt is the weight of the edge
// and dist[u] signifies the shortest distance to reach node u found until now. Similarly,
// dist[v](maybe infinite) signifies the shortest distance to reach node v found until now.
// If the distance to reach v through u(i.e. dist[u] + wt) is smaller than dist[v], we will update
// the value of dist[v] with (dist[u] + wt). This process of updating the distance is called the 
// relaxation of edges.

// How to detect a negative cycle?
// If we do another iteration after N-1 iterations, and the distance array reduces still, we will prove that there is
// a negative cycle in the graph as we need max N-1 iterations to calculate the shortest path. This means that
// if the distance keeps on decreasing, there is a negative cycle in the graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        // doing V - 1 iterations for Bellman Ford
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                // if a shorter path exists, update it. Similar to dijkstra's algorithm
                if (dist[v] > wt + dist[u] && dist[u] != 1e8)
                {
                    dist[v] = wt + dist[u];
                }
            }
        }
        
        // checking whether a negative cycle exists by doing one more relaxation
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[v] > wt + dist[u] && dist[u] != 1e8)
            {
                // if on Nth iteration, distance is still reducing, then negative cycle exists
                return {-1};
            }
        }
        // if not, then return the dist vector array
        return dist;
    }
};