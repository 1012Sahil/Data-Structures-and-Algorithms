// the Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect
// negative cycles as well.
// In Floyd Warshall’s algorithm, we need to check every possible path going via each possible node.
// And after checking every possible path, we will figure out the shortest path(a kind of brute force
// approach to find the shortest path).
// Formula : matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]),
// where i = source node, j = destination node, and k = the node via which we are reaching from i to j.
// Here we will calculate dist[i][j] for every possible node k (k = 0, 1….V, where V = no. of nodes), and
// will select the minimum value as our result.
// In order to apply this algorithm to an undirected graph, we just need to convert the undirected edges
// into directed edges.

// How to detect whether a graph has a negative cycle by floyd warshall algorithm?
// If we find that the cost of reaching any node from itself is less than 0 (CHECK DIAGONAL OF MATRIX), we can conclude
// that the graph has a negative cycle.
// Adjacency Matrix: The adjacency matrix should store the edge weights for the given edges and the rest
// of the cells must be initialized with infinity().

/* Steps to implement the algorithm :
1) After having set the adjacency matrix accordingly, we will run a loop from 0 to V-1(V = no. of vertices). In
the kth iteration, this loop will help us to check the path via node k for every possible pair of nodes.
Basically, this loop will change the value of k in the formula.
2) Inside the loop, there will be two nested loops for generating every possible pair of
nodes(Nothing but to visit each cell of a 2D matrix using the nested loop). Among these two loops,
the first loop will change the value of i and the second one will change the value of j in the formula.
3) Inside these nested loops, we will apply the above formula to calculate the shortest distance between
the pair of nodes.
4) Finally, the adjacency matrix will store all the shortest paths. For example, matrix[i][j] will store
the shortest path from node i to node j.
*/
#include <bits/stdc++.h>
using namespace std;

// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted
// directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes
// the weight of the edge from i to j. If Matrix[i][j] = -1, it means there is no edge from i to j.

// Time Complexity : O(V^3)
class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // Just change unreachable nodes to 1e9 instead of -1 so as to avoid confusion
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                    matrix[i][j] = 0; // diagonal!
            }
        }

        // Floyd-Warshall
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // For negative cycle detection
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][i] < 0)
            {
                cout << "NEGATIVE CYCLE EXISTS" << endl;
                break;
            }
        }

        // Change the unreachable node to -1 again as that's what the question demands in the end
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
                if (i == j)
                    matrix[i][j] = 0; // diagonal!
            }
        }
    }
};