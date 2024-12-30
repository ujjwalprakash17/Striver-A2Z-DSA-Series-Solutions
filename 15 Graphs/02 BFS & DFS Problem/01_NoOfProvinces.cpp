#include <bits/stdc++.h>
using namespace std;

void dfsTraversal(int node, vector<vector<int>> &adjList, vector<int> &visited)
{
    visited[node] = 1;
    for (int i : adjList[node])
    {
        if (!visited[i])
            dfsTraversal(i, adjList, visited);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int V = isConnected.size();
    vector<vector<int>> adjList(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            int val = isConnected[i][j];
            if (val == 1)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    int cnt = 0;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsTraversal(i, adjList, visited);
            cnt++;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}