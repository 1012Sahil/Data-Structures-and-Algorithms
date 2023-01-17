#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm will not work for negative weighted graphs because the traversal will fall
// into an infinite loop, as the distance keeps on decreasing, it will go back and forth b/w
// the two nodes and never stop!

// Time Complexity : E log(V)

// We are using a pq over a q so as to minimise the number of iterations we need to go through. When we use a pq
// we first take all the minimal paths, and then if we encounter a longer path, we don't even add it to the pq.
// Such an option is not available in the q, that's just plain brute force technique.
// This approach is a greedy type of approach.

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // We are using PQ over Q as PQ is better
        // Remember this is the way to declare a min PQ, as default is max heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        // set distance of each node as inf except source node
        for (int i = 0; i < V; i++)
            dist[i] = 1e9;
        dist[S] = 0;
        // the src will be 0 distance from itself, push it into pq
        pq.push({0, S});

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // traverse the adj list for all adjacent nodes and check if a shorter path exists!
            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];
                // if yes, then push it into pq
                if (dist[adjNode] > dis + edgeWeight)
                {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
                // if no, continue
            }
        }
        return dist;
    }
};