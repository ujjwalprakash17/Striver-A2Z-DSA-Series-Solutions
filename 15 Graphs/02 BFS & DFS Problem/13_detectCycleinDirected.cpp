#include <bits/stdc++.h>
using namespace std;
//we have a better version of detecting cycles in a graph
bool detectCycle(int start, vector<int> &color, vector<vector<int>> &adjList)
{

    color[start] = 1;
    for (int neighbour : adjList[start])
    {
        if (color[neighbour] == 0)
        {
            if (!detectCycle(neighbour, color, adjList))
                return false;
        }
        else if (color[neighbour] == 1)
            return false;
    }
    color[start] = 2;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    for (auto prereq : prerequisites)
    {
        int u = prereq[0];
        int v = prereq[1];
        adjList[v].push_back(u);
    }
    vector<int> color(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        if (!color[i])
        {
            bool val = detectCycle(i, color, adjList);
            if (!val)
                return false;
        }
    }
    return true;
}

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