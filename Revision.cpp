#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &adj, int src)
{
    // code here
    // using bfs
    int n = adj.size();
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        int currNode = q.front().first;
        int currDist = q.front().second;
        q.pop();
        for (int neighbour : adj[currNode])
        {
            if (dist[neighbour] == 1e9)
            {
                q.push({neighbour, currDist + 1});
            }
            dist[neighbour] = min(dist[neighbour], currDist + 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == 1e9)
        {
            dist[i] = -1;
        }
    }
    return dist;
}
int main()
{

    return 0;
}