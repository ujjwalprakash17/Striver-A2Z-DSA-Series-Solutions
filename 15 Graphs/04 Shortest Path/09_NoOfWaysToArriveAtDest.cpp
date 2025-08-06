#include <bits/stdc++.h>
using namespace std;


int countPaths(int n, vector<vector<int>> &roads)
{
    const int MOD = 1e9 + 7;
    vector<vector<pair<int, int>>> adjList(n);
    for (auto &road : roads)
    {
        int u = road[0], v = road[1], wt = road[2];
        adjList[u].emplace_back(v, wt);
        adjList[v].emplace_back(u, wt);
    }

    vector<long long> dist(n, LLONG_MAX); 
    vector<int> ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [currDist, currNode] = pq.top();
        pq.pop();

        if (currDist > dist[currNode]) continue;

        for (auto &[neighbor, wt] : adjList[currNode])
        {
            long long newDist = currDist + wt;
            if (newDist < dist[neighbor])
            {
                dist[neighbor] = newDist;
                ways[neighbor] = ways[currNode];
                pq.push({newDist, neighbor});
            }
            else if (newDist == dist[neighbor])
            {
                ways[neighbor] = (ways[neighbor] + ways[currNode]) % MOD;
            }
        }
    }

    return ways[n - 1];
}


int main()
{

    return 0;
}