#include <bits/stdc++.h>
using namespace std;
// using dfs traversal
bool dfsTraversal(int node, vector<vector<int>> adj, vector<int> &visited, vector<int> &pathVisited)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (dfsTraversal(neighbour, adj, visited, pathVisited) == true)
                return true;
        }
        else if (pathVisited[neighbour])
        {
            return true;
        }
    }
    // Unmarking the node from pathVisited ensures that when you backtrack,
    // you no longer consider the node as part of the current path.
    // This is crucial because other parts of the graph may need to use the same node,
    // and unmarking it prevents incorrect cycle detection in subsequent traversals
    pathVisited[node] = 0;
    return false;
}
bool isCyclic(int V, vector<vector<int>> adj)
{
    // code here
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfsTraversal(i, adj, visited, pathVisited) == true)
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}