#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int node, vector<int> &visited, vector<int> adj[])
{
    visited[node] = 1;
    for(auto it: adj[node])
    {
        if(!visited[it])
        dfsTraversal(it, visited, adj);
    }

}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int V = isConnected.size();
    vector<int> adj[V];
    for(int i = 0;i  < V; i++)
    {
        for(int j = 0; j < V ; j++)
        {
            if(isConnected[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> visited(V, 0);
    for(int i = 0; i < V; i++)
    {
        dfsTraversal(i, visited, adj);
    }
}

int main()
{

    return 0;
}