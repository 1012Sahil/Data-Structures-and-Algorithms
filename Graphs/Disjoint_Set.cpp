// Union By rank/ Union by Size

// Link : https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/

// UNION BY RANK -
// Why connect smaller chain to larger?
// -> Because we don't want to increase the height, as if the height increases, we take a longer distance to
// find the ultimate parent

// Functionalities of Disjoint Set data structure:
// The disjoint set data structure generally provides two types of functionalities:

// Finding the parent for a particular node (findPar())
// Union (in broad terms this method basically adds an edge between two nodes)
// Union by rank
// Union by size

// Union by rank:
// Before discussing Union by rank we need to discuss some terminologies:

// Rank:
// The rank of a node generally refers to the distance (the number of nodes including the leaf node) between
// the furthest leaf node and the current node. Basically rank includes all the nodes beneath the current node.

/*         1
         /   \        Here the rank of node 1 is 2 as the distance
        2     3       between node 1 and the furthest leaf node 4 is 2.
       /
      4

Ultimate parent:
      The parent of a node generally refers to the node right above that particular node. But the
      ultimate parent refers to the topmost node or the root node.

In order to implement Union by rank, we basically need two arrays of size N(no. of nodes). One is the
rank and the other one is the parent.
*/

/*
The algorithm steps are as follows:
Firstly, the Union function requires two nodes(let’s say u and v) as arguments. Then we will find the
ultimate parent (using the findPar() function that is discussed later) of u and v. Let’s consider the
ultimate parent of u is pu and the ultimate parent of v is pv.
After that, we will find the rank of pu and pv.
Finally, we will connect the ultimate parent with a smaller rank to the other ultimate parent with
a larger rank. But if the ranks are equal, we can connect any parent to the other parent and we will
increase the rank by one for the parent node to whom we have connected the other one.


If we try to find the ultimate parent(typically using recursion) of each query separately, it will end
up taking O(logN) time complexity for each case. But we want the operation to be done in a constant time.
This is where the path compression technique comes in.

What is path compression?
Basically, connecting each node in a particular path to its ultimate parent refers to path compression.
*/

// UNION BY SIZE -
/*
The size array will be storing the size for each particular node i.e. size[i] will be the size of the
component starting from node i. Typically, the size of a node refers to the number of nodes that are
connected to it.

The algorithm steps are as follows:

Firstly, the Union function requires two nodes(let’s say u and v) as arguments. Then we will find the ultimate
parent (using the findPar() function discussed earlier) of u and v. Let’s consider the ultimate parent of u
is pu and the ultimate parent of v is pv.
After that, we will find the size of pu and pv i.e. size[pu] and size[pv].
Finally, we will connect the ultimate parent with a smaller size to the other ultimate parent with
a larger size. But if the size of the two is equal, we can connect any parent to the other parent.
While connecting in both cases we will increase the size of the parent node to whom we have connected
by the size of the other parent node which is actually connected.
*/

// Time Complexity:  The time complexity is O(4α) which is very small and close to 1.
// So, we can consider 4α as a constant.

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

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}