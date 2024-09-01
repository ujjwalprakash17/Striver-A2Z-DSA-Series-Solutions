#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges)
{
    // Code here
    vector<vector<int>> adj(V); //took a adjacency list to store graph V is no of nodes
    for (int i = 0; i < edges.size(); i++)
    {
        // since it is undirected graph hence we can store like this
        adj[edges[i].first].push_back(edges[i].second); //in adj[0].push_back(1);
        adj[edges[i].second].push_back(edges[i].first); //in adj[1].push_back(0);
    }
    return adj;
}

int main()
{

    return 0;
}