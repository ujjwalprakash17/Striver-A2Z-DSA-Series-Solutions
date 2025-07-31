#include <bits/stdc++.h>
using namespace std;

// steps to find Shortest Path is :
// 1. find topoSort of the graph
// 2. Then relax the edges using Dist array

void dfsTraversal(int start, vector<vector<pair<int, int>>> &adjList, vector<int> &visited, stack<int> &st)
{
    visited[start] = 1;
    for (auto neighbour : adjList[start])
    {
        int neighbourNode = neighbour.first;
        if (!visited[neighbourNode])
        {
            dfsTraversal(neighbourNode, adjList, visited, st);
        }
    }
    st.push(start);
}

vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
{
    // code here
    vector<vector<pair<int, int>>> adjList(V);
    // converted this into adjList
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int dist = edges[i][2];
        adjList[u].push_back({v, dist});
    }

    stack<int> st;
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsTraversal(i, adjList, visited, st);
        }
    }
    // now we got the topoSort into st
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        for (auto neighbour : adjList[curr])
        {
            int neighbourNode = neighbour.first;
            int neighbourDist = neighbour.second;
            if (dist[curr] != INT_MAX)
            {
                dist[neighbourNode] = min(dist[neighbourNode], dist[curr] + neighbourDist);
            }
        }
    }
    for (int &ele : dist)
    {
        if (ele == INT_MAX)
        {
            ele = -1;
        }
    }
    return dist;
}

int main()
{

    return 0;
}