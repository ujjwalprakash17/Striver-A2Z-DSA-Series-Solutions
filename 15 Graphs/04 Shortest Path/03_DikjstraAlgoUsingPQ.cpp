#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    // Code here
    // initial configuration
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // declare a distance array where the answers will be stored
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    // put the source node into the pq
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        // now traverse the neighbour node
        for (auto it : adj[currNode])
        {
            int neighbourNode = it.first;
            int distanceOfNeighbour = it.second;
            if (currDist + distanceOfNeighbour < dist[neighbourNode])
            {
                dist[neighbourNode] = currDist + distanceOfNeighbour;
                pq.push({currDist + distanceOfNeighbour, neighbourNode});
            }
        }
    }
    return dist;
}

int main()
{

    return 0;
}