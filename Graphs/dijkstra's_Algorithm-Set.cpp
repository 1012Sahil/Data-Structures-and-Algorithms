#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm will not work for negative weighted graphs because the traversal will fall
// into an infinite loop, as the distance keeps on decreasing, it will go back and forth b/w
// the two nodes and never stop!

// Time Complexity : E log(V)

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // USING SET
        set<pair<int, int>> st;
        // declare all distances to be inf and set  distance of src to itself as 0
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty())
        {
            // dereference the iterator to access the elements
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            // similar to pop in pq
            st.erase(it);

            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgeWeight = it[1];
                // if a less costlier path exists
                if (dist[adjNode] > dis + edgeWeight)
                {
                    // if the node is not visited for the first time and still a better path exists,
                    // then it means that the current path in set can be discarded! Remove it!
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});

                    dist[adjNode] = dis + edgeWeight;
                    // insert the better path in set
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};