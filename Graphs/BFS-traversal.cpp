#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(N) + O(2E) ---> Total N nodes are visited and for each node it runs for all its degree (== 2E)
// 'V' is the number of nodes and 's' is the node number we have to start our traversal from
void BFS(vector<int> adj[], int V, int s)
{
	bool visited[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		cout << u << " ";

		// Iterating over the vector at the uth index of 'adj' vector as that itself is a vector
		// For each 'v', check if it's already been visited, if not, add it to queue
		for (int v : adj[u])
		{
			if (visited[v] == false)
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 2, 3);
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 4);
	addEdge(adj, 2, 4);

	cout << "Following is Breadth First Traversal: " << endl;
	BFS(adj, V, 0);

	return 0;
}
