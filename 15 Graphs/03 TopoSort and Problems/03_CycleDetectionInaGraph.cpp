#include <bits/stdc++.h>
using namespace std;

// Detect cycle in a graph using bfs

bool bfsTraversal(int currNode, vector<vector<int>> &adj, vector<int> &visited)
{
    queue<int> q;
    q.push(currNode);
    visited[currNode] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(int V, vector<vector<int>> adj)
{
    // code here
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (bfsTraversal(i, adj, visited) == true)
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}