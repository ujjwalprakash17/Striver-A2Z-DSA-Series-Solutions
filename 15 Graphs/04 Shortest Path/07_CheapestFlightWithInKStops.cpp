#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pair<int, int>>> adjList(n);
    for (auto &flight : flights)
    {
        int u = flight[0];
        int v = flight[1];
        int wt = flight[2];
        adjList[u].push_back({v, wt});
    }

    // dist[node][stops] = min cost to reach 'node' with 'stops' number of flights
    vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
    dist[src][0] = 0;

    // set: {cost, {stops, node}}
    set<pair<int, pair<int, int>>> setDS;
    setDS.insert({0, {0, src}});

    while (!setDS.empty())
    {
        auto [currPrice, info] = *setDS.begin();
        setDS.erase(setDS.begin());
        int stops = info.first;
        int node = info.second;

        // Don't go beyond k+1 nodes (which is k stops)
        if (stops > k)
            continue;

        for (auto [nei, cost] : adjList[node])
        {
            int totalPrice = currPrice + cost;
            if (totalPrice < dist[nei][stops + 1])
            {
                dist[nei][stops + 1] = totalPrice;
                setDS.insert({totalPrice, {stops + 1, nei}});
            }
        }
    }

    // Find the minimum price to reach dst with at most k+1 nodes (i.e., k stops)
    int minCost = 1e9;
    for (int i = 0; i <= k + 1; i++)
    {
        minCost = min(minCost, dist[dst][i]);
    }

    return minCost == 1e9 ? -1 : minCost;
}

int main()
{

    return 0;
}